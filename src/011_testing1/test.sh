#!/bin/bash

####
#
# OPTIONAL
#
# This file will help you get started writing some automated tests,
# but it is NOT an exhaustive list of possible test cases.
#
# You don't HAVE to write automated tests, however it sure beats
# manually invoking each program with different parameters
#
# You can run this file locally, and it will also be run when you
# publish your branch to Gitlab
#
####

# $1 - program number to test
# $2 - value to test with
compareResults() {
  num=$1
  val=$2

  test="isPrime-broken$num"

  # invoke the $test program with $val and capture the output
  out=$("./$test" "$val")

  # invoke isPrime-correct with $val and capture the output
  cor=$( "YOUR CODE HERE" )

  # compare the output
  if [ "$out" != "$cor" ]
  then
    return 1
  fi

  return 0
}

start=0
end=3

for ((i=1;i<5;i++))
do
  # begin testing with the value of "start"
  # stop testing once we reach "end"
  for ((x=start;x<end;x++))
  do
    compareResults "$i" "$x"

    # "$?" captures the "return" value from compareResults
    if [ "$?" = "1" ]
    then
      echo "Found broken value $x for program $i"
      echo ""
      # write broken value $x to file "input.$i"
      echo "$x" > "./input.$i"
      break
    else
      continue
    fi
  done

  # what other test cases should we consider...?
  # YOUR ADDITIONAL CODE HERE

done

echo "Exiting tests..."
exit 0
