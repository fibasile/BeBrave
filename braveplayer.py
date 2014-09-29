#!/usr/bin/python

import subprocess
import time

VIDEO_PATH='/home/pi/video.avi'
TRAILER_PATH='/home/pi/video.avi'
PLAYER_CMD = '/usr/bin/omxplayer'


def playVideo(path):
    print 'Play video'
    args = [PLAYER_CMD, path]
    process = subprocess.Popen(args)
    return process

def loopVideo(path):
    print 'Loop video'
    args = [PLAYER_CMD, '-loop', path]
    process = subprocess.Popen(args)
    return process

while True:
    p = playVideo(VIDEO_PATH)
    while p.poll() == None:
       time.sleep(1)
       print 'Running'


