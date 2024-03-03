#!/bin/sh

if [ "$#" -ne 2 ]; then
  echo "Usage: ./mergesort.sh number_of_bars output_file_name"
  exit 1
fi

rm "${dir}"/*.*

bin/mergesort "$1"

dir="JGRfiles"
output_dir="Output"

for file in "$dir"/*; do
  filename=$(basename "$file" | cut -d. -f1)
  output="$dir/${filename}.png"
  jgraph -P "$file" | ps2pdf - | convert -density 300 - -quality 100 "$output"
done

ffmpeg -framerate 25 -i "${dir}/%d-ms.png" -vf scale=-2:1080 -pix_fmt yuv420p "${output_dir}/${2}.mp4"

