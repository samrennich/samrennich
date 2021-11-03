#!/bin/bash

# Check every repository for status

# Text Colors
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
NC=$(tput sgr0)

# For every dir...
for d in */; do
  cd $d # Move to dir

  # If there are changes...
  if [ -n "$(git status --porcelain)" ]; then
    printf "%-20s %s\n" $d "${RED}Changes${NC}"
  else # If there are no changes...
    printf "%-20s %s\n" $d "${GREEN}No Changes${NC}"
  fi

  cd .. # Move back
done
