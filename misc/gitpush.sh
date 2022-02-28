#!/bin/bash

if [[ $1 == "--help" ]]
then
	printf "Usage: bash gitpush.sh [optional -flag]\n"
	printf "Flags:\n"
	printf "[-no flag] Push to own git repo\n"
	printf "[-v] Push to own git and vogsphere repo\n"
	exit 1
elif [[ $1 && $1 != '-v' ]]
then
	printf "bash gitpush.sh --help for more info\n"
	exit 1
fi

if [[ $1 == '-v' ]]
then
	printf "Pushing to own git and vog\ngit commit message: "
	read input
	git add .
	git commit -m "$input"
	git push
elif [[ ! $1 ]]
then
	printf "Pushing to own git\ngit commit message: "
	read input
	git add .
	git commit -m "$input [skip ci]"
	git push
fi