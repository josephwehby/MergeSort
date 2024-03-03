# MergeSort
- Joseph Wehby
- cs 494 UTK

# Description
- This program produces an mp4 file that displays a visualization of the mergesort algorithm. 
- the user is able to specify the number of elements to sort and the output file
- All of the images and jgr files generated will live in The JGRFiles directory and will be removed whenever the program is run again

# Build and Run
- make sure jgraph is installed which can be found [Jgraph](https://web.eecs.utk.edu/~jplank/plank/jgraph/jgraph.html)
- you will also need ffmpeg, psd2pdf, and convert which can be installed with a package manager
- clone the repo with `git clone`
- run `make` to build the mergesort executable
- run `./mergesort.sh number_of_bars video_file_name`

# Example Command
- `./mergesort.sh 30 randombars` will sort 30 bars and save the animation to Output/randombars.mp4

# Tips
- The framerate is currently set to 25 so make sure to use a reasonable number of bars or the video will be too quick.

# For the TA
For the example command that generates only a few frames run `./mergesort.sh 2 filename` and then look in the JGRFiles directory to see the images and jgr files it has generated. This will still try to ffmpeg but that will not impact the images and jgr files already created so you will still be able to see them. You will most likely get an error that ffmpeg is not installed.
