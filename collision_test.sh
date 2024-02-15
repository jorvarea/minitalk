#!/bin/bash

# Command template
CMD="./bin/client $1 $2"

# Run the command in the background 10 times with a delay between each
for i in {1..3}; do
    eval $CMD &
    sleep 0.005
done

# Wait for all background jobs to finish
wait

