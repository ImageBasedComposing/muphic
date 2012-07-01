---------------------------------------------------------------------
---------------------------------------------------------------------

	 /$$      /$$ /$$   /$$ /$$$$$$$  /$$   /$$ /$$$$$$  /$$$$$$ 
	| $$$    /$$$| $$  | $$| $$__  $$| $$  | $$|_  $$_/ /$$__  $$
	| $$$$  /$$$$| $$  | $$| $$  \ $$| $$  | $$  | $$  | $$  \__/
	| $$ $$/$$ $$| $$  | $$| $$$$$$$/| $$$$$$$$  | $$  | $$      
	| $$  $$$| $$| $$  | $$| $$____/ | $$__  $$  | $$  | $$      
	| $$\  $ | $$| $$  | $$| $$      | $$  | $$  | $$  | $$    $$
	| $$ \/  | $$|  $$$$$$/| $$      | $$  | $$ /$$$$$$|  $$$$$$/
	|__/     |__/ \______/ |__/      |__/  |__/|______/ \______/ 
															 
---------------------------------------------------------------------
---------------------------------------------------------------------
															 

-- So, What's this? --

	Muphic is the Final Year Project of 3 students in their last year of computer engineering at Complutense University of Madrid. It's an expermental software that uses static images as an input for automatic composition algorithms developed by the project members.
	
	Any feedback will be welcome, and please keep in mind this is still a work in progress.
	

-- Installation --

	.- Windows users:
		Download, unzip and exec GUIQt.exe
		
	.- Linux users:
		Download, unzip, make, and exec Muphic/bin/Debug/ExecMe
		It will ask you for your user password, but don't worry, as it doesn't really install anything on your computer.
		
		Note: In order to use the application on Linux systems, these libraries will have to be installed first:

		.- qt libs version 4.7.4 (libqt4-dev recommended)
		.- libphonon-dev (multimedia framework from KDE-development files)
		.- libphonon4 (multimedia framework from KDE-core library)
		.- phonon (multimedia framework from KDE-metapackage)
		.- phonon-backend-gstreamer (Phonon GStreamer 0.10.x backend)
		.- libqtscript4-phonon (Qt Script bindings for the Qt 4 Phonon library)
			
-- Main usage -

	1. Start application
	2. Load an image
	3. Choose an output path
	4. Change analysis options as you please (under the "Graphic Config" tab).
	5. Click Analyze. Go eat something if you chose to do thorough analysis (click "Stop" if you get tired of it). If not, see magic happens.
	6. Change composing options as you please under the "Composition Config" tab).
	7. Click Compose. Composing takes no time (this step creates a .mid file), but converting to .wav takes a while, so don't panic.
	8. Click play and enjoy!


-- More about Muphic --

	Muphic can analyze and compose images in lots of ways, and hopefully this section will cover that information in the future. We will first explain the “Graphic Config” tab, followed by the “Composition Config” one.

	For those who follow tl;dr ad their main motto, just know that Hue Division is the fastest and accurate of all implemented filters, so don't choose canny. Please.

		
	-- Analysis Configuration--

	Lots of things can be changed in this tab:

		.- Noise Selecion: using this slider, you’ll be able to select the minimum size of the figures below which they will be considered noise (and will therefore be ignored). This value is actually a percentaje of the global area: if you select 30, it means that all figures with an area lower than 0.3*globalArea will be ignored (ignoring several polygons will make the analysis go faster):

		.- Analysis Depth: this slider allows you to change the level of detail of the analysis process: a higher value will make the process become more exhaustive but slower; a lower one will make it faster but simpler.

		.- Polygon Simplification: once all color shapes have been detected, each will be turned into a list of vertex using an approximation. This slider will control the accuracy of this approximation: the lower the value, the more accurate it is.

		.- Filter: different filters will result in different way of detecting shapes. Each one of them will turn the image into several b&w images (each of them containing the information of some shapes), which will be later analyzed in order to detect contours.


		There are several filters available:

			.-Threshold: transforms the image into grayscale, then sets all pixels with a gray value above a given threshold to white, and the rest to black. The value of said threshold can be modified.
				It works pretty fast, but gives very simple results.

			.- Adaptive Threshold: works as the previous filter with one exception: it uses different thresholds in different regions of the image depending on the value of the surrounding pixels.
			It’s a little bit slower than the Threshold filter (but still pretty darn fast).

			.- Canny: uses a region detection algorithm by John F. Canny. Shapes are obtained by checking these region detection.

			.- Hue Division: this is one of our homemade filters, and it detects color spots as neighbor pixels with “similar” RGB values. The greater the “Color Levels” is, the less pixels will be considered “similar”. A higher value on the “Color Levels” slider means that two pixels will have be really close (in terms of RGB values) in order for them to be considered “similar”.

			.- Color Threshold: another homemade filters. It works just like the Threshold filter, but it doesn’t turn the image into grayscale: it uses three different thresholds in three different color channels (Hue, Saturation and Value).


	-- Composition Configuration --

		Some things can be changed in this tab, plus all 4 music voices: voice 1 is the main melody, voice 2 is the secondary melody, third melody bass and the last one is the rhythm.	

			.- Color System: lets you choose the synaesthetic rules that will determine the association between colors and notes.
				
			.- Composers:
					Simple Figure: an obsolete composer that we developed at an early stage of the development, and is included here out of nostalgia. It doesn’t sound GREAT, but give it a try.

					Complex Figure: the latest developed composer, it works with figure positioning, size, color and angle variation. It can do main melodies, secondary melodies and, amazingly, bass too (we didn’t expect that, really).

					Figure Bass: a pretty simple composer that generates bass accompaniments.

					Advanced Rhythm Figure: generates the rhythm voice.

					Mute: no sound!
					
				.- Instruments: you can choose the different instruments you want for each voice..

				.- Mixer: This guy here is in charge of selecting how you want the different voices mixed. Jimmy is our old mixer and he may not give pretty results. Timothy, on the other hand, is our little gem.

				.- Tempo: you can change the tempo of the music that’s going to be composed.


-- Where can I try it? -

	The application can be downloaded here:
	http://code.google.com/p/muphic/downloads/list
	
	Some music pieces composed by our muphic software will be uploaded to this channel:
	http://www.youtube.com/user/mrmuphic
	

-- Troubleshooting --

	1. If, for any reason, the music-player does not work, you will find a .mid and .wav file in the output directory, so you can listen to those manually. Nevertheless, please inform us if such a dreadful thing happens.
	
	2. Some images don't show up on the "Input Image" widget, but never mind that, the rest of the application will work just fine. Working on that.

-- Contact --

	Do you hate us? Do you love us? Do you have any ideas? Please contact us at:
	imagebasedcomposing@gmail.com