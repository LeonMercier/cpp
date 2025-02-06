# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 12:25:49 by lemercie          #+#    #+#              #
#    Updated: 2025/02/06 16:14:23 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#!/bin/bash

infile=./file.txt
outfile1=file.txt.replace
outfile2=sed_out.txt

# replaces chars just like sed
printf "TEST 1\n"
echo hallo > $infile
echo hello > $infile
./seddy $infile a B
sed 's/a/B/g' $infile > $outfile2
if cmp -s $outfile1 $outfile2; then
	printf "yay\n"
else
	printf "nay\n"
fi
rm -f $outfile1 $outfile2 $infile

# if string1 is an empty string, do nothing
printf "TEST 2\n"
echo hallo > $infile
echo hello > $infile
./seddy $infile "" B
if [ -e $outfile1 ]; then
	printf "nay\n"
else
	printf "yay\n"
fi
rm -f $outfile1 $outfile2

# replace with nothing
printf "TEST 3\n"
echo hallo > $infile
echo hello > $infile
./seddy $infile "a" ""
sed 's/a//g' $infile > $outfile2
if cmp -s $outfile1 $outfile2; then
	printf "yay\n"
else
	printf "nay\n"
fi
rm -f $outfile1 $outfile2 $infile

# replace with a string containing space
printf "TEST 4\n"
echo hallo > $infile
echo hello > $infile
./seddy $infile a "Baba yaya"
sed 's/a/Baba yaya/g' $infile > $outfile2
if cmp -s $outfile1 $outfile2; then
	printf "yay\n"
else
	printf "nay\n"
fi
rm -f $outfile1 $outfile2 $infile

# replace with space
printf "TEST 5\n"
echo hallo > $infile
echo hello > $infile
./seddy $infile asd " "
sed 's/asd/ /g' $infile > $outfile2
if cmp -s $outfile1 $outfile2; then
	printf "yay\n"
else
	printf "nay\n"
fi
rm -f $outfile1 $outfile2 $infile

# no read from infile
printf "TEST 6\n"
echo hallo > $infile
echo hello > $infile
chmod -r $infile
./seddy $infile a B
if [ -e $outfile1 ]; then
	printf "nay\n"
else
	printf "yay\n"
fi
rm -f $outfile1 $outfile2 $infile

# no write to outfile
printf "TEST 7\n"
echo hallo > $infile
echo hello > $infile
touch $outfile1
chmod -w $outfile1
./seddy $infile a B
if [ -s $outfile1 ]; then
	printf "nay\n"
else
	printf "yay\n"
fi
rm -f $outfile1 $outfile2 $infile

