#!/bin/bash

if [ "$1" == "aca" ]
then
    if [ "$2" == "start" ]
    then
        git fetch upstream
        git checkout master
        git merge upstream/master
    elif [ "$2" == "commit" ]
    then
        git add *
        git commit -m "$3" -a
        git push
    fi
elif [ "$1" == "zi" ]
then
    if [ "$2" == "start" ]
    then
        git pull
        git request-pull master https://github.com/AionCode/Parmecium.git aca
    elif [ "$2" == "commit" ]
    then
        git add *
        git commit -m "$3" -a
        git push
    fi
fi
