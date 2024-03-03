# MergeSort
- Joseph Wehby
- cs 494 UTK

# Description
- This program produces an mp4 file that displays a visualization of the mergesort algorithm. 
- the user is able to specify the number of elements to sort and the output file


# Build and Run
- make sure jgraph is installed which can be found [Jgraph](https://web.eecs.utk.edu/~jplank/plank/jgraph/jgraph.html)
- you will also need ffmpeg, psd2pdf, and convert which can be installed with a package manager
- clone the repo with `git clone`
- run `make` to build the mergesort executable
- run `./mergesort.sh number_of_bars video_file_name`

# Example Command
`./mergesort.sh 30 random_bars`

# Tips
- The framerate is currently set to 25 so make sure to use a reasonable number of bars or the video will be too quick.
