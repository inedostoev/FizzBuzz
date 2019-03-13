test/tests
test/tests string check
test/tests 1 3 5400000000000000000
test/tests 1.c 1 3 4
test/tests 1 2 3 4 5 6 7 15
test/tests -1 -2 -3 -4 -5 -6 -7 -15
test/tests +1 +2 +3 +4 +5 +6 +7 +15
test/tests 10 15 35 000 -2 -67 -55


OUTPUT="$(diff test/outputFile test/validOutput)"
if [[ $OUTPUT == "" ]] 
then
    echo "Unit tests passed"
else 
    echo "Unit tests fauled"
    echo "$OUTPUT"
fi

rm test/outputFile
