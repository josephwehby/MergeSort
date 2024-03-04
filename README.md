# MergeSort
- Joseph Wehby
- cs 494 UTK

# Description
- This program produces an mp4 file that displays a visualization of the mergesort algorithm. 
- the user is able to specify the number of elements to sort and the output file
- All of the images and jgr files generated will live in the JGRFiles directory and will be removed whenever the program is run again

# Build and Run
- make sure jgraph is installed which can be found [here](https://web.eecs.utk.edu/~jplank/plank/jgraph/jgraph.html)
- you will also need ffmpeg, psd2pdf, and convert which can be installed with a package manager
- clone the repo with `git clone`
- run `make` to build the mergesort executable or `make examples` to generate example videos
- run `./mergesort.sh number_of_bars video_file_name`

# Example Command
- `./mergesort.sh 30 randombars` will sort 30 bars and save the animation to Output/randombars.mp4

# Example Output
- Example videos can be found in the Examples folder
- you can either download the videos or click on the YouTube links located in Examples/examples.md

# Tips
- The framerate is currently set to 25 so make sure to use a reasonable number of bars or the video will be too quick.

# For the TA
For the example command that generates only a few frames run `./mergesort.sh 2 filename` and then look in the JGRFiles directory to see the images and jgr files it has generated. you might need to run it a few times to see different frames though as there is a chance the bars generated are already sorted. This will still try to run ffmpeg but that will not impact the images and jgr files already created so you will still be able to see them. You will get an error that ffmpeg is not installed. Additionally, as requested, the Examples folder will contain a markdown file with links to the example videos uploaded on YouTube and will also have the actual videos in there. Additionally, per the lab writeup, the makefile will will compile 5 examples by running `make examples`. I elected for this as these videos take a long time to make so it made more sense to not run this command every time `make` is run but instead make it separate command.  
