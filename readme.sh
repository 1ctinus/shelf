function readme {

    echo "$1" > '/home/james/code/1ctinus/README.md'
    cd /home/james/code/1ctinus/
    git add README.md
    git commit -m "AUTOMATED $(date '+%F_%H:%M:%S')"
    git push -f origin main

}