/*
    cbp2make : Makefile generation tool for the Code::Blocks IDE
    Copyright (C) 2010-2011 Mirai Computing (mirai.computing@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//------------------------------------------------------------------------------
#include <iostream>
//------------------------------------------------------------------------------
#include "revision.h"
#include "macros.h"
#include "cbproject.h"
#include "cbptarget.h"
#include "cbpunit.h"
#include "cbbuildcfg.h"
#include "cbhelper.h"
#include "stlconvert.h"
#include "stlfutils.h"
#include "depsearch.h"
#include "tinyxml.h"
//------------------------------------------------------------------------------

CCodeBlocksProject::CCodeBlocksProject(void)
{
 Clear();
}

CCodeBlocksProject::~CCodeBlocksProject(void)
{
 Clear();
}

void CCodeBlocksProject::Clear(void)
{
 //m_ValidProject = false;
 m_VersionMajor = 0;
 m_VersionMinor = 0;
 m_Title.Clear();
 m_DefaultTarget.Clear();
 m_Compiler.Clear();
 m_ExtendedObjectNames = false;
 m_CompilerOptions.Clear();
 m_CompilerDirectories.Clear();
 m_ResourceCompilerDirectories.Clear();
 m_LinkerOptions.Clear();
 m_LinkerLibraries.Clear();
 m_LinkerDirectories.Clear();
 m_BeforeBuildCommands.Clear();
 m_AfterBuildCommands.Clear();
 m_ForceBeforeBuildCommands = false;
 m_ForceAfterBuildCommands = false;
 m_Platforms.Clear();
 m_SinglePlatform = true;
 m_BuildTargetIndex.clear();
 m_VirtualTargetIndex.clear();
 m_UnitIndex.clear();
 m_ToolChainIndex.clear();
 //m_MakefileText.Clear();
 m_Makefile.Clear();
 for (size_t i = 0; i < m_BuildTargets.size(); i++) delete m_BuildTargets[i];
 for (size_t i = 0; i < m_VirtualTargets.size(); i++) delete m_VirtualTargets[i];
 for (size_t i = 0; i < m_Units.size(); i++) delete m_Units[i];
 //
 m_BuildTargets.clear();
 m_VirtualTargets.clear();
 m_Units.clear();
}

void CCodeBlocksProject::Read(const TiXmlElement *ProjectRoot)
{
 const TiXmlNode *_version = ProjectRoot->FirstChild("FileVersion");
 if (0!=_version)
 {
  const TiXmlElement *version = _version->ToElement();
  if (0!=version)
  {
   version->QueryIntAttribute("major",&m_VersionMajor);
   version->QueryIntAttribute("minor",&m_VersionMinor);
 }} // file version
 const TiXmlNode *_project = ProjectRoot->FirstChild("Project");
 if (0!=_project)
 {
  TiXmlNode *_option = (TiXmlNode *)_project->FirstChild("Option");
  while (0!=_option)
  {
   TiXmlElement* option = _option->ToElement();
   if (0!=option)
   {
    char *value = 0;
    if ((value = (char *)option->Attribute("title")))
    {
     m_Title = value;
    }
    if ((value = (char *)option->Attribute("default_target")))
    {
     m_DefaultTarget = value;
    }
    if ((value = (char *)option->Attribute("compiler")))
    {
     m_Compiler = value;
    }
    if ((value = (char *)option->Attribute("extended_obj_names")))
    {
     m_ExtendedObjectNames = StringToBoolean(value);
    }
   }
   _option = (TiXmlNode *)_project->IterateChildren(_option);
  } // option
  TiXmlNode *_build = (TiXmlNode *)_project->FirstChild("Build");
  if (0!=_build)
  {
   TiXmlNode *_target = (TiXmlNode *)_build->FirstChild("Target");
   while (0!=_target)
   {
    TiXmlElement* target = _target->ToElement();
    if (strcmp(target->Value(),"Target")) break;
    if (0!=target)
    {
     CBuildTarget *build_target = new CBuildTarget();
     build_target->Read(target);
     m_BuildTargets.push_back(build_target);
    }
    _target = (TiXmlNode *)_build->IterateChildren(_target);
   } // target
   TiXmlNode *_env = (TiXmlNode *)_build->FirstChild("Environment");
   if (0!=_env)
   {
    TiXmlElement* env = _env->ToElement();
    if (0!=env)
    {
     TiXmlNode *_var = (TiXmlNode *)_env->FirstChild("Variable");
     while (0!=_var)
     {
      TiXmlElement* var = _var->ToElement();
      if (0!=var)
      {
       char *value = 0;
       CString env_name, env_value;
       if ((value = (char *)var->Attribute("name")))
       {
        env_name = value;
       }
       if ((value = (char *)var->Attribute("value")))
       {
        env_value = value;
       }
       m_Environment.InsertStringVariable(env_name,env_value);
      }
      _var = (TiXmlNode *)_env->IterateChildren(_var);
     }
    } // variable
   } // environment
  } // build
  TiXmlNode *_vtarget = (TiXmlNode *)_project->FirstChild("VirtualTargets");
  if (0!=_vtarget)
  {
   TiXmlElement *vtarget = _vtarget->ToElement();
   if (0!=vtarget)
   {
    TiXmlNode *_option = (TiXmlNode *)_vtarget->FirstChild("Add");
    if (0!=_option)
    {
     TiXmlElement* option = _option->ToElement();
     if (0!=option)
     {
      CVirtualTarget *v_target = new CVirtualTarget();
      v_target->Read(option);
      m_VirtualTargets.push_back(v_target);
     }
     _option = (TiXmlNode *)_vtarget->IterateChildren(_option);
    } // option
   }
  } // vtargets
  TiXmlNode *_compiler = (TiXmlNode *)_project->FirstChild("Compiler");
  if (0!=_compiler)
  {
   TiXmlNode *_option = (TiXmlNode *)_compiler->FirstChild("Add");
   while (0!=_option)
   {
    TiXmlElement* option = _option->ToElement();
    if (0!=option)
    {
     char *value = 0;
     if ((value = (char *)option->Attribute("option")))
     {
      m_CompilerOptions.Insert(value);
     }
     if ((value = (char *)option->Attribute("directory")))
     {
      m_CompilerDirectories.Insert(value);
     }
    }
    _option = (TiXmlNode *)_compiler->IterateChildren(_option);
   } // option
  } // compiler
  TiXmlNode *_res_compiler = (TiXmlNode *)_project->FirstChild("ResourceCompiler");
  if (0!=_res_compiler)
  {
   TiXmlNode *_option = (TiXmlNode *)_res_compiler->FirstChild("Add");
   while (0!=_option)
   {
    TiXmlElement* option = _option->ToElement();
    if (0!=option)
    {
     char *value = 0;
     if ((value = (char *)option->Attribute("directory")))
     {
      m_ResourceCompilerDirectories.Insert(value);
     }
    }
    _option = (TiXmlNode *)_res_compiler->IterateChildren(_option);
   } // option
  } // resource compiler
  TiXmlNode *_linker = (TiXmlNode *)_project->FirstChild("Linker");
  if (0!=_linker)
  {
   TiXmlNode *_option = (TiXmlNode *)_linker->FirstChild("Add");
   while (0!=_option)
   {
    TiXmlElement* option = _option->ToElement();
    if (0!=option)
    {
     char *value = 0;
     if ((value = (char *)option->Attribute("option")))
     {
      m_LinkerOptions.Insert(value);
     }
     if ((value = (char *)option->Attribute("directory")))
     {
      m_LinkerDirectories.Insert(value);
     }
     if ((value = (char *)option->Attribute("library")))
     {
      m_LinkerLibraries.Insert(value);
     }
    }
    _option = (TiXmlNode *)_linker->IterateChildren(_option);
   } // option
  } // linker
  TiXmlNode *_extra_cmd = (TiXmlNode *)_project->FirstChild("ExtraCommands");
  if (0!=_extra_cmd)
  {
   TiXmlNode *_option = (TiXmlNode *)_extra_cmd->FirstChild("Add");
   while (0!=_option)
   {
    TiXmlElement* option = _option->ToElement();
    if (0!=option)
    {
     if (strcmp(option->Value(),"Add")) break;
     char *value = 0;
     if ((value = (char *)option->Attribute("before")))
     {
      m_BeforeBuildCommands.Insert(value);
     }
     if ((value = (char *)option->Attribute("after")))
     {
      m_AfterBuildCommands.Insert(value);
     }
    }
    _option = (TiXmlNode *)_extra_cmd->IterateChildren(_option);
   } // option
   _option = (TiXmlNode *)_extra_cmd->FirstChild("Mode");
   while (0!=_option)
   {
    TiXmlElement* option = _option->ToElement();
    if (0!=option)
    {
     if (strcmp(option->Value(),"Mode")) break;
     char *value = 0;
     if ((value = (char *)option->Attribute("before")))
     {
      m_ForceBeforeBuildCommands = (strcmp(value,"always")==0);
     }
     if ((value = (char *)option->Attribute("after")))
     {
      m_ForceAfterBuildCommands = (strcmp(value,"always")==0);
     }
    }
    _option = (TiXmlNode *)_extra_cmd->IterateChildren(_option);
   } // option
  } // extra commands
  TiXmlNode *_unit = (TiXmlNode *)_project->FirstChild("Unit");
  while (0!=_unit)
  {
   TiXmlElement* unit = _unit->ToElement();
   if (0!=unit)
   {
    if (strcmp(unit->Value(),"Unit")) break;
    CBuildUnit *build_unit = new CBuildUnit();
    build_unit->Read(unit);
    m_Units.push_back(build_unit);
   }
   _unit = (TiXmlNode *)_project->IterateChildren(_unit);
  } // unit
 } // project
 // add default target if project has no targets
 if (m_BuildTargets.size()==0)
 {
  CBuildTarget *target = new CBuildTarget();
  m_BuildTargets.push_back(target);
 }
 // generate object names for units
 /*
 for (size_t i = 0; i < m_Units.size(); i++)
 {
  if (m_ExtendedObjectNames)
  {
   m_Units[i]->m_ObjectFileName = m_Units[i]->m_FileName+".o";
  }
  else
  {
   m_Units[i]->m_ObjectFileName = ChangeFileExt(m_Units[i]->m_FileName,".o");
  }
 }
 */
 // sort units by weight
 SortUnitsByWeight();
}

bool CCodeBlocksProject::LoadProject(const CString& FileName)
{
 bool result = false;
 TiXmlDocument cbp;
 result = cbp.LoadFile(FileName.GetCString());
 if (!result) return false;
 Clear();
 const TiXmlElement *root = cbp.RootElement();
 if (0==strcmp(root->Value(),"CodeBlocks_project_file"))
 {
  Read(root);
  result = true;
 } // root value
 return result;
}

/*
void CCodeBlocksProject::DecorateTargetNames(void)
{
 for (int i = 0, n = m_BuildTargets.size(); i < n; i++)
 {
  CBuildTarget *target = m_BuildTargets[i];
  CString name = DecorateTargetName(target->m_Title);
  target->UCName() = UpperCase(name);
  target->LCName() = LowerCase(name);
  CString path = RemoveTrailingPathDelimiter(target->ObjectOutput());
  target->ObjectOutput() = path;
 }
 for (int i = 0, n = m_VirtualTargets.size(); i < n; i++)
 {
  CVirtualTarget *target = m_VirtualTargets[i];
  CString name = DecorateTargetName(target->m_Alias);
  target->UCName() = UpperCase(name);
  target->LCName() = LowerCase(name);
 }
}
*/

class CUnitWeightComparison
{
 public:
  bool operator ()(CBuildUnit *const &AUnit, CBuildUnit *const &BUnit)
  {
   return (AUnit->m_Weight < BUnit->m_Weight);
  }
};

void CCodeBlocksProject::SortUnitsByWeight(void)
{
 /*for (int i = 0, n = m_Units.size(); i < n; i++)
 {
  std::cout<<m_Units[i]->m_Filename.GetString()<<","<<m_Units[i]->m_Weight<<std::endl;
 }*/
 CUnitWeightComparison cmp;
 std::sort(m_Units.begin(),m_Units.end(),cmp);
 /*for (int i = 0, n = m_Units.size(); i < n; i++)
 {
  std::cout<<m_Units[i]->m_Filename.GetString()<<","<<m_Units[i]->m_Weight<<std::endl;
 }*/
}

void CCodeBlocksProject::Show(void)
{
 std::cout<<"Project title: "<<m_Title.GetString()<<std::endl;
 std::cout<<"Project version: "<<m_VersionMajor<<"."<<m_VersionMinor<<std::endl;
 std::cout<<"Default target: "<<m_DefaultTarget.GetString()<<std::endl;
 std::cout<<"Default compiler: "<<m_Compiler.GetString()<<std::endl;
 std::cout<<"Compiler options: "<<m_CompilerOptions.GetCount()<<std::endl;
 for (int i = 0, n = m_CompilerOptions.GetCount(); i < n; i++)
 {
  std::cout<<"Option #"<<(i+1)<<": "<<m_CompilerOptions[i].GetString()<<std::endl;
 }
 std::cout<<"Compiler directories: "<<m_CompilerDirectories.GetCount()<<std::endl;
 for (int i = 0, n = m_CompilerDirectories.GetCount(); i < n; i++)
 {
  std::cout<<"Directory #"<<(i+1)<<": "<<m_CompilerDirectories[i].GetString()<<std::endl;
 }
 std::cout<<"Linker options: "<<m_LinkerOptions.GetCount()<<std::endl;
 for (int i = 0, n = m_LinkerOptions.GetCount(); i < n; i++)
 {
  std::cout<<"Option #"<<(i+1)<<": "<<m_LinkerOptions[i].GetString()<<std::endl;
 }
 std::cout<<"Linker directories: "<<m_LinkerDirectories.GetCount()<<std::endl;
 for (int i = 0, n = m_LinkerDirectories.GetCount(); i < n; i++)
 {
  std::cout<<"Directory #"<<(i+1)<<": "<<m_LinkerDirectories[i].GetString()<<std::endl;
 }
 std::cout<<"Linked libraries: "<<m_LinkerLibraries.GetCount()<<std::endl;
 for (int i = 0, n = m_LinkerLibraries.GetCount(); i < n; i++)
 {
  std::cout<<"Library #"<<(i+1)<<": "<<m_LinkerLibraries[i].GetString()<<std::endl;
 }
 std::cout<<"Build targets: "<<m_BuildTargets.size()<<std::endl;
 for (int i = 0, n = m_BuildTargets.size(); i < n; i++)
 {
  std::cout<<"Target #"<<(i+1)<<std::endl;
  CBuildTarget *build_target = m_BuildTargets[i];
  build_target->Show();
 }
 std::cout<<"Virtual targets: "<<m_VirtualTargets.size()<<std::endl;
 for (int i = 0, n = m_VirtualTargets.size(); i < n; i++)
 {
  std::cout<<"Target #"<<(i+1)<<std::endl;
  CVirtualTarget *v_target = m_VirtualTargets[i];
  v_target->Show();
 }
 std::cout<<"Units: "<<m_Units.size()<<std::endl;
 for (int i = 0, n = m_Units.size(); i < n; i++)
 {
  std::cout<<"Unit #"<<(i+1)<<": ";
#ifndef SHOW_MODE_ONELINE
  std::cout<<std::endl;
#endif
  CBuildUnit *build_unit = m_Units[i];
  build_unit->Show();
 }
 ShowStringList("Before-build commands","Command",m_BeforeBuildCommands);
 std::cout<<"Force before-build commands: "
          <<BooleanToYesNoString(m_ForceBeforeBuildCommands).GetCString()<<std::endl;
 ShowStringList("After-build commands","Command",m_AfterBuildCommands);
 std::cout<<"Force after-build commands: "
          <<BooleanToYesNoString(m_ForceAfterBuildCommands).GetCString()<<std::endl;
}

void CCodeBlocksProject::UpdatePlatformIndex
 (const size_t Platform, CCodeBlocksBuildConfig& Config)
{
 m_BuildTargetIndex.clear();
 m_VirtualTargetIndex.clear();
 m_ToolChainIndex.clear();
 //
 CString platform_name = Config.Platforms().Platform(Platform)->Name();
 // add all targets for current platform to index
 for (int i = 0, n = m_BuildTargets.size(); i < n; i++)
 {
  CBuildTarget *target = m_BuildTargets[i];
  CStringList platforms = target->Platforms();
  bool add_target = ((platforms.GetCount()==0) ||
   ((platforms.GetCount()>0) && (platforms.FindString(platform_name)>=0)));
  add_target &= ((Config.Targets().GetCount()==0) ||
   ((Config.Targets().GetCount()>0) && (Config.Targets().FindString(target->Title())>=0)));
  if (add_target)
  {
   m_BuildTargetIndex.push_back(target);
  }
 }
 // add all virtual targets containing valid targets to index
 for (int i = 0, ni = m_VirtualTargets.size(); i < ni; i++)
 {
  bool done = false;
  CVirtualTarget *v_target = m_VirtualTargets[i];
  for (int j = 0, nj = v_target->Targets().GetCount(); j < nj; j++)
  {
   for (int k = 0, nk = m_BuildTargetIndex.size(); k < nk; k++)
   {
    CBuildTarget *target = m_BuildTargetIndex[k];
    if (target->Title() == v_target->Targets().GetString(j))
    {
     m_VirtualTargetIndex.push_back(v_target);
     done = true; break;
    }
   }
   if (done) break;
  }
  if (done) break;
 }
 // collect unique toolchains for all targets
 Config.ToolChains().Lock();
 //
 m_TargetToolChainIndex.clear();
 CStringList tc_names;
 tc_names.Insert(m_Compiler);
 for (int j = 0, nj = m_BuildTargetIndex.size(); j < nj; j++)
 {
  CBuildTarget *target = m_BuildTargetIndex[j];
  tc_names.Insert(target->Compiler());
 }
 tc_names.RemoveEmpty();
 tc_names.RemoveDuplicates();
 // add all uniqie toolchains to index
 for (int j = 0, nj = tc_names.GetCount(); j < nj; j++)
 {
  CPlatform::OS_Type platform = Config.Platforms().Platform(Platform)->OS();
  for (int i = 0, ni = Config.ToolChains().GetCount(platform); i < ni; i++)
  {
   CToolChain *tc = Config.ToolChains().ToolChain(platform,i);
   if (tc->Alias() == tc_names[j])
   {
    //std::cout<<"unique toolchain index = "<<j<<std::endl;
    //std::cout<<"toolchain index = "<<i<<std::endl;
    //std::cout<<"toolchain alias = "<<tc->Alias().GetCString()<<std::endl;
    m_ToolChainIndex.push_back(tc);
    break;
   }
  }
 }
 //std::cout<<std::endl;
 // build per-target toolchain index
 for (int j = 0, nj = m_BuildTargetIndex.size(); j < nj; j++)
 {
  CBuildTarget *target = m_BuildTargetIndex[j];
  CString tc_name = target->Compiler();
  if (tc_name.IsEmpty()) tc_name = m_Compiler;
  int index = tc_names.FindString(tc_name);
  if (index >= 0)
  {
   //std::cout<<"target title = "<<target->Title().GetCString()<<std::endl;
   //std::cout<<"target compiler = "<<tc_name.GetCString()<<std::endl;
   //std::cout<<"toolchain index = "<<index<<std::endl;
   m_TargetToolChainIndex.push_back(index);
  }
 }
 //std::cout<<std::endl;
}

void CCodeBlocksProject::UpdateTargetIndex
 (const int Target, CCodeBlocksBuildConfig& Config)
{
 //std::cout<<"Clearing unit index ..."<<std::endl;
 m_UnitIndex.clear();
 //std::cout<<"Building unit index ..."<<std::endl;
 // add all units for current target to index;
 CBuildTarget *target = m_BuildTargetIndex[Target];
 //std::cout<<"Target #"<<Target<<" title is "<<target->Title().GetCString()<<std::endl;
 for (int i = 0, ni = m_Units.size(); i < ni; i++)
 {
  CBuildUnit *unit = m_Units[i];
  if (unit->BelongToTarget(target->Title()))
  {
   //std::cout<<"+++ Unit #"<<(i+1)<<" "<<unit->FileName().GetCString()
   //         <<" belongs to target "<<target->Title().GetCString()<<std::endl;
   m_UnitIndex.push_back(unit);
  }
  else
  {
   //std::cout<<"--- Unit #"<<(i+1)<<" "<<unit->FileName().GetCString()
   //         <<" does not belong to target "<<target->Title().GetCString()<<std::endl;
   //m_UnitIndex.push_back(unit);
  }
 }
 //std::cout<<"Unit index is updated."<<std::endl;
}

CString CCodeBlocksProject::DecorateTargetName(const CString& TargetName, const int Case)
{
 CString result = MakefileFriendly(TargetName);
 switch (Case)
 {
  default:
  case 0: return result;
  case 1: return LowerCase(result);
  case 2: return UpperCase(result);
 }
}

CString CCodeBlocksProject::DecorateVariableName(const CString& VariableName, const int Case)
{
 CString result = MakefileFriendly(VariableName);
 switch (Case)
 {
  default:
  case 0: return result;
  case 1: return LowerCase(result);
  case 2: return UpperCase(result);
 }
}

bool CCodeBlocksProject::GenerateMakefile
 (const CString& FileName, CCodeBlocksBuildConfig& Config)
{
 m_Dependencies.Clear();
 // setup decorated target names
 //DecorateTargetNames();
 for (size_t i = 0; i < m_BuildTargets.size(); i++)
 {
  m_BuildTargets[i]->NameCase() = Config.TargetNameCase();
 }
 for (size_t i = 0; i < m_VirtualTargets.size(); i++)
 {
  m_VirtualTargets[i]->NameCase() = Config.TargetNameCase();
 }
 //
 int active_platforms = 0;
 for (size_t pi = 0, pn = Config.Platforms().GetCount(); pi < pn; pi++)
 {
  if (Config.Platforms().Platform(pi)->Active()) active_platforms++;
 }
 m_SinglePlatform = (1==active_platforms);
 //
 CString cwd = GetCurrentDir();
 for (size_t pi = 0, pn = Config.Platforms().GetCount(); pi < pn; pi++)
 {
  CPlatform *pl = Config.Platforms().Platform(pi);
  if (!pl->Active()) continue;
  CString makefile_path = ExtractFilePath(FileName);
  CString makefile_name = ExtractFileName(FileName);
  CString platform_name = pl->Name();
  if (!m_SinglePlatform) makefile_name += "."+LowerCase(platform_name);
  UpdatePlatformIndex(pi,Config);
  if (!makefile_path.IsEmpty())
  {
   ChangeDir(makefile_path);
  }
  m_Dependencies.Platform() = *pl;
  CConfiguration cmd_args;
  // begin makefile
  m_Makefile.Clear();
  int section = 0;
  // head comment
  const int header_width = 80;
  m_Makefile.Header().Insert(FillStr("#",'-',"#",header_width));
#ifdef REVISION_NUMBER
  {
   CString rn = IntegerToString(REVISION_NUMBER);
   CString line = FillStr("# This makefile was generated by 'cbp2make' tool rev."+rn,' ',"#",header_width);
   m_Makefile.Header().Insert(line);
  }
#else
  CString line = FillStr("# This makefile was generated by 'cbp2make' tool rev.",' ',"#",header_width)
#endif
  m_Makefile.Header().Insert(FillStr("#",'-',"#",header_width));
  m_Makefile.Header().Insert("");
  section++;
  // standard macros
  CString STR_WRKDIR = DecorateVariableName("WorkDir",Config.MacroVariableCase());
  CString STR_INC = DecorateVariableName("Inc",Config.MacroVariableCase());
  CString STR_LIB = DecorateVariableName("Lib",Config.MacroVariableCase());
  CString STR_DEP = DecorateVariableName("Dep",Config.MacroVariableCase());
  CString STR_OBJ = DecorateVariableName("Obj",Config.MacroVariableCase());
  CString STR_OUT = DecorateVariableName("Out",Config.MacroVariableCase());
  CString STR_CFLAGS = DecorateVariableName("CFlags",Config.MacroVariableCase());
  CString STR_RCFLAGS = DecorateVariableName("RCFlags",Config.MacroVariableCase());
  CString STR_LDFLAGS = DecorateVariableName("LDFlags",Config.MacroVariableCase());
  CString STR_RESINC = DecorateVariableName("ResInc",Config.MacroVariableCase());
  CString STR_LIBDIR = DecorateVariableName("LibDir",Config.MacroVariableCase());
  CString STR_OBJDIR = DecorateVariableName("ObjDir",Config.MacroVariableCase());
  // macros
  CString line = pl->EvalWorkDir();
  m_Makefile.AddMacro(STR_WRKDIR,line,section);
  section++;
  // declare environment variables
  if (m_Environment.GetCount())
  {
   for (int i = 0; i < m_Environment.GetCount(); i++)
   {
    m_Makefile.AddEnvVar(m_Environment.Variable(i).GetName(),
                         m_Environment.Variable(i).GetString(),section);
   }
  }
  section++;
  // declare global compiler variables
  for (size_t i = 0; i < Config.GlobalVariables().Count(); i++)
  {
   CGlobalVariableSet *vset = Config.GlobalVariables().Get(i);
   if (0!=vset) if (vset->Active())
   {
    for (size_t j = 0; j < vset->Count(); j++)
    {
     CGlobalVariable *v = vset->Get(j);
     m_Makefile.AddMacro(DecorateVariableName(v->Name(),
      Config.MacroVariableCase()),v->Convert(v->Base()),section);
     m_Makefile.AddMacro(DecorateVariableName(v->Name()+".include",
      Config.MacroVariableCase()),v->Convert(v->Include()),section);
     m_Makefile.AddMacro(DecorateVariableName(v->Name()+".lib",
      Config.MacroVariableCase()),v->Convert(v->Lib()),section);
     m_Makefile.AddMacro(DecorateVariableName(v->Name()+".obj",
      Config.MacroVariableCase()),v->Convert(v->Obj()),section);
     m_Makefile.AddMacro(DecorateVariableName(v->Name()+".cflags",
      Config.MacroVariableCase()),v->Convert(v->Cflags()),section);
     m_Makefile.AddMacro(DecorateVariableName(v->Name()+".lflags",
      Config.MacroVariableCase()),v->Convert(v->Lflags()),section);
     for (int k = 0; k < v->Count(); k++)
     {
      m_Makefile.AddMacro(DecorateVariableName(v->Name()+"."+v->GetField(k),
       Config.MacroVariableCase()),v->Convert(v->GetValue(k)),section);
   }}}
   section++;
  }
  // make variables of build tools
  int tc_section = section;
  bool single_toolchain = (m_ToolChainIndex.size()==1);
  for (size_t i = 0; i < m_ToolChainIndex.size(); i++)
  {
   CToolChain *tc = m_ToolChainIndex[i];
   CString tc_suffix; if (!single_toolchain) tc_suffix = IntegerToString(i);
   for (size_t j = 0; j < tc->ToolsCount(); j++)
   {
    CBuildTool *bt = tc->GetBuildTool(j);
    m_Makefile.AddMacro(
     DecorateVariableName(bt->MakeVariable()+tc_suffix,Config.MacroVariableCase()),
     bt->Program(),section);
   }
  }
  section++;
  // base flags
  line.Clear();
  for (int i = 0; i < m_CompilerDirectories.GetCount(); i++)
  {
   line += " -I"+pl->Pd(m_CompilerDirectories[i]);
  }
  m_Makefile.AddMacro(STR_INC,CGlobalVariable::Convert(line,Config.MacroVariableCase()),section);
  line.Clear();
  for (int i = 0; i < m_CompilerOptions.GetCount(); i++)
  {
   line += " "+m_CompilerOptions[i];
  }
  m_Makefile.AddMacro(STR_CFLAGS,CGlobalVariable::Convert(line,Config.MacroVariableCase()),section);
  m_Makefile.AddMacro(STR_RESINC,"",section);
  //m_Makefile.AddMacro("RCFLAGS","",section);//not supported by CB build system
  line.Clear();
  for (int i = 0; i < m_LinkerDirectories.GetCount(); i++)
  {
   line += " -L"+pl->Pd(m_LinkerDirectories[i]);
  }
  m_Makefile.AddMacro(STR_LIBDIR,CGlobalVariable::Convert(line,Config.MacroVariableCase()),section);
  line.Clear();
  for (int i = 0; i < m_LinkerLibraries.GetCount(); i++)
  {
   CString lib_name = m_LinkerLibraries[i];
   CString lib_ext = ExtractFileExt(lib_name);
   if (lib_ext.IsEmpty())
   {
    line += " -l"+pl->Pd(lib_name);
   }
   else
   {
    line += " "+pl->Pd(lib_name);
   }
  }
  m_Makefile.AddMacro(STR_LIB,CGlobalVariable::Convert(line,Config.MacroVariableCase()),section);
  line.Clear();
  for (int i = 0; i < m_LinkerOptions.GetCount(); i++)
  {
   line += " "+m_LinkerOptions[i];
  }
  m_Makefile.AddMacro(STR_LDFLAGS,CGlobalVariable::Convert(line,Config.MacroVariableCase()),section);
  section++;
  // per-target flags
  for (size_t t = 0; t < m_BuildTargetIndex.size(); t++)
  {
   CBuildTarget *target = m_BuildTargetIndex[t];
   m_Makefile.AddMacro(target->Name(STR_INC+"_",Config.MacroVariableCase()),
    CGlobalVariable::Convert(pl->Pd(target->IncDirs(" $("+STR_INC+")")),Config.MacroVariableCase()),section);
   m_Makefile.AddMacro(target->Name(STR_CFLAGS+"_",Config.MacroVariableCase()),
    CGlobalVariable::Convert(pl->Pd(target->CFlags(" $("+STR_CFLAGS+")")),Config.MacroVariableCase()),section);
   m_Makefile.AddMacro(target->Name(STR_RESINC+"_",Config.MacroVariableCase()),
    CGlobalVariable::Convert(pl->Pd(target->ResDirs(" $("+STR_RESINC+")")),Config.MacroVariableCase()),section);
   m_Makefile.AddMacro(target->Name(STR_RCFLAGS+"_",Config.MacroVariableCase()),
    CGlobalVariable::Convert(pl->Pd(target->RCFlags(" $("+STR_RCFLAGS+")")),Config.MacroVariableCase()),section);
   m_Makefile.AddMacro(target->Name(STR_LIBDIR+"_",Config.MacroVariableCase()),
    CGlobalVariable::Convert(pl->Pd(target->LibDirs(" $("+STR_LIBDIR+")")),Config.MacroVariableCase()),section);
   m_Makefile.AddMacro(target->Name(STR_LIB+"_",Config.MacroVariableCase()),
    CGlobalVariable::Convert("$("+STR_LIB+")"+pl->Pd(target->Libs(pl->OS())),Config.MacroVariableCase()),section);
   m_Makefile.AddMacro(target->Name(STR_LDFLAGS+"_",Config.MacroVariableCase()),
    CGlobalVariable::Convert(pl->Pd(target->LdFlags(" $("+STR_LDFLAGS+")")),Config.MacroVariableCase()),section);
   line = pl->Pd(target->ObjectOutput());
   if (target->ObjectOutput().IsEmpty()) line += ".objs";
   m_Makefile.AddMacro(target->Name(STR_OBJDIR+"_",Config.MacroVariableCase()),
                       CGlobalVariable::Convert(line,Config.MacroVariableCase()),section);
   m_Makefile.AddMacro(target->Name(STR_DEP+"_",Config.MacroVariableCase()),pl->Pd(target->ExtDeps()),section);
   CString target_output = target->Output();
   /*
   if (target->m_AutoPrefix)
   {
    //
   }
   */
   if (CBuildTarget::ttCommands!=target->Type())
   {
    if (target->AutoExtension())
    {
     CString ext = target->AutoFileExtension(platform_name);
     //target_output = ChangeFileExt(target_output,ext);
     if (!ext.IsEmpty())
     {
      target_output += "."+ext;
     }
    }
    m_Makefile.AddMacro(target->Name(STR_OUT+"_",Config.MacroVariableCase()),pl->Pd(target_output),section);
   }
   section++;
  }
  int target_objects_section = section;
  // common units
  // per-target units
  for (size_t t = 0; t < m_BuildTargetIndex.size(); t++)
  {
   CBuildTarget *target = m_BuildTargetIndex[t];
   if (CBuildTarget::ttCommands==target->Type()) continue;
   section++;
  }
  bool have_global_commands = (m_BeforeBuildCommands.GetCount()>0)
                            || (m_AfterBuildCommands.GetCount()>0);
  // default virtual targets
  CMakefileRule& rule_all = m_Makefile.AddRule
   (DecorateTargetName("all",Config.TargetNameCase()),section);
  for (size_t t = 0; t < m_BuildTargetIndex.size(); t++)
  {
   CBuildTarget *target = m_BuildTargetIndex[t];
   if (have_global_commands)
   {
    rule_all.Dependencies().Insert(target->Name("build_"));
   }
   else
   {
    rule_all.Dependencies().Insert(target->Name(""));
   }
  }
  CMakefileRule& rule_clean = m_Makefile.AddRule
   (DecorateTargetName("clean",Config.TargetNameCase()),section);
  for (size_t t = 0; t < m_BuildTargetIndex.size(); t++)
  {
   CBuildTarget *target = m_BuildTargetIndex[t];
   if (CBuildTarget::ttCommands!=target->Type())
   {
    rule_clean.Dependencies().Insert(target->Name("clean_"));
   }
  }
  // global before-build commands
  if (have_global_commands)//(m_BeforeBuildCommands.GetCount()>0)
  {
   CString name = DecorateTargetName("before_build",Config.TargetNameCase());
   CMakefileRule& rule = m_Makefile.AddRule(name,section);
   rule.Commands().Insert(m_BeforeBuildCommands);
   rule_all.Dependencies().InsertAt(0,name);
  }
  // global after-build commands
  if (have_global_commands)//(m_AfterBuildCommands.GetCount()>0)
  {
   CString name = DecorateTargetName("after_build",Config.TargetNameCase());
   CMakefileRule& rule = m_Makefile.AddRule(name,section);
   rule.Commands().Insert(m_AfterBuildCommands);
   rule_all.Dependencies().Insert(name);
  }
  // build targets
  for (size_t t = 0; t < m_BuildTargetIndex.size(); t++)
  {
   CBuildTarget *target = m_BuildTargetIndex[t];
   UpdateTargetIndex(t,Config);
   CStringList before_build_commands = target->BeforeBuildCommands();
   CStringList after_build_commands = target->AfterBuildCommands();
   // setup suffix for toolchain if there are more than one toolchain
   int tc_id = m_TargetToolChainIndex[t];
   CToolChain *tc = m_ToolChainIndex[tc_id];
   CString tc_suffix;
   if (!single_toolchain) tc_suffix = IntToStr(tc_id);
   //
   CString target_out_name = "$("+target->Name(STR_OUT+"_",Config.MacroVariableCase())+")";
   CMakefileRule& rule_before = m_Makefile.AddRule(target->Name("before_"),section);
   CMakefileRule& rule_after = m_Makefile.AddRule(target->Name("after_"),section);
   CMakefileRule& rule_build_target = m_Makefile.AddRule(target->Name(""),section);
   //CMakefileRule& rule_target = rule_build_target;
   if (have_global_commands)
   {
    rule_build_target.Target() = target->Name("build_");
    CMakefileRule& rule_target = m_Makefile.AddRule(target->Name(""),section);
    // global before-build commands
    if (have_global_commands)//(m_BeforeBuildCommands.GetCount()>0)
    {
     rule_target.Dependencies().Insert
      (DecorateTargetName("before_build",Config.TargetNameCase()));
    }
    rule_target.Dependencies().Insert(rule_build_target.Target());
    // global after-build commands
    if (have_global_commands)//(m_AfterBuildCommands.GetCount()>0)
    {
     rule_target.Dependencies().Insert
      (DecorateTargetName("after_build",Config.TargetNameCase()));
    }
   }
   rule_build_target.Dependencies().Insert(target->Name("before_"));
   if (CBuildTarget::ttCommands!=target->Type())
   {
    // output binary name may be exactly same for different targets
    // and shouldn't be used as makefile rule name
    //rule_target.Dependencies().Insert(target_out_name);
    rule_build_target.Dependencies().Insert(target->Name("out_"));
   }
   rule_build_target.Dependencies().Insert(target->Name("after_"));
   // before-build commands target
   if (before_build_commands.GetCount())
   {
#ifdef TARGET_WRKDIR_ENABLED
    if (!target->m_WorkingDirectory.IsEmpty())
    {
     rule_before.Commands().Insert(pl->Cd()+" "+pl->Pd(target->m_WorkingDirectory));
    }
#endif
    rule_before.Commands().Insert(before_build_commands);
   }
   // after-build commands target
   if (after_build_commands.GetCount())
   {
    rule_after.Commands().Insert(after_build_commands);
#ifdef TARGET_WRKDIR_ENABLED
    if (!target->m_WorkingDirectory.IsEmpty())
    {
     rule_after.Commands().Insert(pl->Cd()+" $("+STR_WRKDIR+")");
    }
#endif
   }
   if (CBuildTarget::ttCommands!=target->Type())
   {
    CMakefileVariable& target_objects = m_Makefile.AddMacro(target->Name(STR_OBJ+"_",Config.MacroVariableCase()),"",target_objects_section++);
    target_objects.Multiline() = Config.MultilineObjects();
    // output binary name may be exactly same for different targets
    // and shouldn't be used as makefile rule name
    //CMakefileRule& rule_target_out = m_Makefile.AddRule(target_out_name,section);
    CMakefileRule& rule_target_out = m_Makefile.AddRule(target->Name("out_"),section);
    rule_target_out.Dependencies().Insert("$("+target->Name(STR_OBJ+"_",Config.MacroVariableCase())+")");
    rule_target_out.Dependencies().Insert("$("+target->Name(STR_DEP+"_",Config.MacroVariableCase())+")");
    CStringList target_directories;
    CStringList clean_target_directories;
    CString binary_path = ExtractFilePath(target->Output());
    if (!binary_path.IsEmpty())
    {
     target_directories.Insert(pl->Pd(binary_path));
     if (!Config.KeepOutputDirectories())
     {
      clean_target_directories.Insert(pl->Pd(binary_path));
     }
    }
    CString object_extension = "x";
    //
    cmd_args.SetStringVariable(TPL_LIB_DIRS,"$("+target->Name(STR_LIBDIR+"_",Config.MacroVariableCase())+")");
    cmd_args.SetStringVariable(TPL_LIBS,"$("+target->Name(STR_LIB+"_",Config.MacroVariableCase())+")");
    cmd_args.SetStringVariable(TPL_LNK_OBJECTS,"$("+target->Name(STR_OBJ+"_",Config.MacroVariableCase())+")");
    cmd_args.SetStringVariable(TPL_LNK_RES_OBJECTS,"");
    cmd_args.SetStringVariable(TPL_LNK_OPTIONS,"$("+target->Name(STR_LDFLAGS+"_",Config.MacroVariableCase())+")");
    //
    switch (target->Type())
    {
     case CBuildTarget::ttStaticLibrary:
     {
      // get a static linker (if any)
      CStaticLinker *linker = dynamic_cast<CStaticLinker *>(tc->GetBuildTool(0,CBuildTool::btStaticLinker));
      if (0!=linker)
      {
       // compose static linkage command
       cmd_args.SetStringVariable(TPL_LIB_LINKER,"$("+DecorateVariableName(linker->MakeVariable()+tc_suffix,Config.MacroVariableCase())+")");
       cmd_args.SetStringVariable(TPL_STL_OUTPUT,"$("+target->Name(STR_OUT+"_",Config.MacroVariableCase())+")");
       line = linker->MakeCommand(cmd_args);
       //
       rule_target_out.Commands().Insert(line);
       object_extension = linker->ObjectExtension();
      }
      else
      {
       if (Config.BeVerbose())
       {
        std::cout<<"Cannot link target '"<<target->Name("").GetCString()<<"', static linker is missing."<<std::endl;
       }
      }
      //line = "$(AR"+tc_suffix+") rcs $(OUT_"+target->UCName()+") $(OBJ_"+target->UCName()+")";
      //rule_target_out.Commands().Insert(line);
      break;
     }
     case CBuildTarget::ttDynamicLibrary:
     {
      // get a dynamic linker (if any)
      CDynamicLinker *linker = dynamic_cast<CDynamicLinker *>(tc->GetBuildTool(0,CBuildTool::btDynamicLinker));
      if (0!=linker)
      {
       // compose dynamic linkage command
       cmd_args.SetStringVariable(TPL_LINKER,"$("+DecorateVariableName(linker->MakeVariable()+tc_suffix,Config.MacroVariableCase())+")");
       cmd_args.SetStringVariable(TPL_EXE_OUTPUT,"$("+target->Name(STR_OUT+"_",Config.MacroVariableCase())+")");
       line = linker->MakeCommand(cmd_args);
       //
       rule_target_out.Commands().Insert(line);
       object_extension = linker->ObjectExtension();
      }
      else
      {
       if (Config.BeVerbose())
       {
        std::cout<<"Cannot link target '"<<target->Name("").GetCString()<<"', dynamic linker is missing."<<std::endl;
       }
      }
      break;
     }
     case CBuildTarget::ttConsoleExecutable:
     case CBuildTarget::ttExecutable:
     case CBuildTarget::ttNative:
     {
      // get an executable linker (if any)
      CExecutableLinker *linker = dynamic_cast<CExecutableLinker *>(tc->GetBuildTool(0,CBuildTool::btExecutableLinker));
      if (0!=linker)
      {
       // compose executable linkage command
       cmd_args.SetStringVariable(TPL_LINKER,"$("+DecorateVariableName(linker->MakeVariable()+tc_suffix,Config.MacroVariableCase())+")");
       cmd_args.SetStringVariable(TPL_EXE_OUTPUT,"$("+target->Name(STR_OUT+"_",Config.MacroVariableCase())+")");
       line = linker->MakeCommand(cmd_args);
       //
       rule_target_out.Commands().Insert(line);
       object_extension = linker->ObjectExtension();
      }
      else
      {
       if (Config.BeVerbose())
       {
        std::cout<<"Cannot link target '"<<target->Name("").GetCString()<<"', executable linker is missing."<<std::endl;
       }
      }
      /*
      if (m_UnitIndex.size() > 0) // probably unneccesary
      {
       line = "$(LD"+tc_suffix+")";
       if (CBuildTarget::ttDynamicLibrary==target->Type())
       {
        line += " -shared";
       }
       line += " $(LDFLAGS_"+target->UCName()+") $(LIBDIR_"
             + target->UCName()+") -o $(OUT_"+target->UCName()+") $(OBJ_"
             + target->UCName()+") $(LIB_"+target->UCName()+")";
       rule_target_out.Commands().Insert(line);
      }
      */
      break;
     }
    }
    if (!object_extension.IsEmpty()) object_extension = "."+object_extension;
    // build units
    for (size_t i = 0; i < m_UnitIndex.size(); i++)
    {
     CBuildUnit *unit = m_UnitIndex[i];
     CCompiler *compiler = tc->FindCompiler(unit->Extension());
     /*
     std::cout<<"target "<<target->Name().GetString()
              <<" unit "<<unit->m_FileName.GetString()
              <<" compilable "<<unit->IsCompilable()
              <<" compile "<<unit->m_DoCompile
              <<" link "<<unit->m_DoLink<<std::endl;
     */
     if (((0!=compiler)||(!unit->CompilerVariable().IsEmpty()))&&(unit->DoCompile()))
     {
      CString compiler_var = compiler->MakeVariable();
      if (unit->CompilerVariable().IsEmpty())
      {
       compiler_var = compiler->MakeVariable();
      }
      else
      {
       compiler_var = unit->CompilerVariable();
      }

      if (compiler->NeedDependencies() && Config.IncludeDependencies())
      {
       CIncludeSearchFilter *filter = compiler->IncludeSearchFilter();
       if (0!=filter)
       {
        filter->AddIncludeDirectories(m_CompilerDirectories);
        filter->AddIncludeDirectories(target->CompilerDirectories());
        filter->Execute(unit->FileName(),m_Dependencies);
        size_t index = m_Dependencies.FindRecord(unit->FileName());
        CStringList unit_deps(m_Dependencies.AllDependencies(index));
        //m_Dependencies.Show();//debug
        //unit_deps.RemoveDuplicates();//depsearch makes rules
        //ShowStringList("unit includes","include",unit_deps);//debug
        if (Config.BeVerbose())
        {
         std::cout<<"["<<(i+1)<<"/"<<m_UnitIndex.size()<<"] "
                  <<m_Dependencies.OneLineReport(index,true,false).GetCString()
                  <<" "<<unit->FileName().GetString()
                  <<std::endl;
        }
       }
      }

      CString object_name;
      if (m_ExtendedObjectNames)
      {
       object_name = pl->Pd(unit->FileName()+object_extension);
      }
      else
      {
       object_name = pl->Pd(ChangeFileExt(unit->FileName(),object_extension));
      }
      if (Config.FlatObjectNames())
      {
       if (Config.FlatObjectPaths())
       {
        object_name = FlatFileName(object_name);
       }
       else
       {
        object_name = ExtractFileName(object_name);
       }
      }
      CString object_prefix = "$("+target->Name(STR_OBJDIR+"_",Config.MacroVariableCase())+")";
      CString object_prefix_name = pl->Pd(JoinPaths(object_prefix,object_name));
      if (unit->DoLink())
      {
       target_objects.AddValue(object_prefix_name);
      }
      CString object_path = pl->Pd(ExtractFilePath(object_name));
      CString unit_name = pl->Pd(unit->FileName());
      CMakefileRule& rule_unit = m_Makefile.AddRule(object_prefix_name,section);
      rule_unit.Dependencies().Insert(unit_name);
      //if (!object_path.IsEmpty() && !target->ObjectOutput().IsEmpty())
      {
       if (object_path.IsEmpty())
       {
        object_path = object_prefix;
       }
       else
       {
        object_path = pl->Pd(JoinPaths(object_prefix,object_path));
       }
       target_directories.Insert(object_path);
       if (!Config.KeepObjectDirectories())
       {
        clean_target_directories.Insert(object_path);
       }
      }
      // compose compilation command
      cmd_args.SetStringVariable(TPL_COMPILER,"$("+DecorateVariableName(compiler_var+tc_suffix,Config.MacroVariableCase())+")");
      cmd_args.SetStringVariable(TPL_INCLUDES,"$("+target->Name(STR_INC+"_",Config.MacroVariableCase())+")");
      cmd_args.SetStringVariable(TPL_OPTIONS,"$("+target->Name(STR_CFLAGS+"_",Config.MacroVariableCase())+")");
      cmd_args.SetStringVariable(TPL_FILE,unit_name);
      cmd_args.SetStringVariable(TPL_OBJECT,object_prefix_name);
      cmd_args.SetStringVariable(TPL_RES_COMPILER,"$("+DecorateVariableName(compiler_var+tc_suffix,Config.MacroVariableCase())+")");
      cmd_args.SetStringVariable(TPL_RES_INCLUDES,"$("+target->Name(STR_RESINC+"_",Config.MacroVariableCase())+")");
      cmd_args.SetStringVariable(TPL_RES_OUTPUT,object_prefix+object_name);
      line = compiler->MakeCommand(cmd_args);
      rule_unit.Commands().Insert(line);
      /*
      if (CBuildUnit::utResource==unit->m_Type)
      {
       line = "$("+compiler_var+tc_suffix+") $(RCFLAGS_"+target->UCName()+") $(RESINC_"
             + target->UCName()+") -J rc -O coff -o "+"$(OBJDIR_"+target->UCName()+")"
             + pl->Pd()+object_name+" -i "+unit_name;
       rule_unit.Commands().Insert(line);
      }
      else
      {
       line = "$("+compiler_var+tc_suffix+") $(CFLAGS_"+target->UCName()+") $(INC_"
             + target->UCName()+") -c -o "+"$(OBJDIR_"+target->UCName()+")"+pl->Pd()
             + object_name+" "+unit_name;
       rule_unit.Commands().Insert(line);
      }
      */
     } // compilable unit
    } // units
    // clean target
    CMakefileRule& rule_clean_target = m_Makefile.AddRule(target->Name("clean_"),section);
    line.Clear();
    //if (pl->OS()==CPlatform::OS_Windows) line += "cmd /c ";
    line += pl->MakefileCmd(pl->ForceRemoveFile(
     "$("+target->Name(STR_OBJ+"_",Config.MacroVariableCase())+
     ") $("+target->Name(STR_OUT+"_",Config.MacroVariableCase())+")"));
    rule_clean_target.Commands().Insert(line);
    // target directories
    target_directories.RemoveDuplicates();
    target_directories.RemoveEmpty();
    for (int i = 0; i < target_directories.GetCount(); i++)
    {
     rule_before.Commands().Insert(pl->MakefileCmd(pl->TestMakeDir(target_directories[i])));
    }
    clean_target_directories.RemoveDuplicates();
    clean_target_directories.RemoveEmpty();
    for (int i = 0; i < clean_target_directories.GetCount(); i++)
    {
     rule_clean_target.Commands().Insert(pl->MakefileCmd(pl->RemoveDir(clean_target_directories[i])));
    }
   }
  } // build target
  // virtual targets
  for (size_t t = 0; t < m_VirtualTargetIndex.size(); t++)
  {
   CVirtualTarget *v_target = m_VirtualTargetIndex[t];
   CMakefileRule& rule_v_target = m_Makefile.AddRule(v_target->Name("virtual_"),section);
   if (have_global_commands)//(m_BeforeBuildCommands.GetCount()>0)
   {
    rule_v_target.Dependencies().Insert(DecorateTargetName("before_build",Config.TargetNameCase()));
   }
   for (int i = 0, n = v_target->Targets().GetCount(); i < n; i++)
   {
    CString child_target_name = DecorateTargetName(v_target->Targets().GetString(i),
                                                   Config.TargetNameCase());
    if (have_global_commands)
    {
     rule_v_target.Dependencies().Insert(DecorateTargetName("build_"+child_target_name,Config.TargetNameCase()));
    }
    else
    {
     rule_v_target.Dependencies().Insert(child_target_name);
    }
   }
   if (have_global_commands)//(m_AfterBuildCommands.GetCount()>0)
   {
    rule_v_target.Dependencies().Insert(DecorateTargetName("after_build",Config.TargetNameCase()));
   }
  }
  section++;
  // depedency rules
  if (Config.IncludeDependencies())
  {
   m_Dependencies.MakeRules(m_Makefile,section,Config.MultilineObjects());
  }
  // save makefile
  CStringList& text = m_Makefile.Update();
  text.SaveToFile(makefile_name);
  m_Makefile.Clear();
  ChangeDir(cwd);
 }
 // clear index
 m_BuildTargetIndex.clear();
 m_VirtualTargetIndex.clear();
 m_ToolChainIndex.clear();
 m_UnitIndex.clear();
 Config.ToolChains().Unlock();
 //
 if (Config.BeVerbose() && Config.IncludeDependencies())
 {
  m_Dependencies.Show();
 }
 return true;
}

//------------------------------------------------------------------------------
