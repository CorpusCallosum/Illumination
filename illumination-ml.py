"""
  illumination.py
  
  by Jack Kalish and Yonatan Ben-Simhon
  NYU ITP 2011
"""

import sys, commands, subprocess, math, re, os, shutil, glob, random, time
from threading import Thread
from MarkovGenerator import MarkovGenerator
import unicodedata

class Illuminate(object):
	def setup(self):

		#clear the terminal
		self.reset()

		#TRAIN THE MARKOV GENERATOR
		print "reading and getting inspiration..."
		self.generator = MarkovGenerator(n=3, max=30, min=4)
	
	def makeNewPoem(self):
		print "thinking of a new poem...",
		#make a new poem between 3 and 14 lines long
		self.lineCnt = 0
		self.wordCnt = 0
		numLines = round(random.random()*11)+3
		print "it will be ",
		print numLines,
		print "lines long"
		print "***THE START***"
		lines =  self.generator.generateFromText(numLines)
		self.lines = lines
		self.line = lines[0]
		self.showTime = 5000
		
	def run(self):
		#stop current poem
		self.makePoems = False
		#clear screen
		background(0)
		self.img = None
		self.loadNewImage()
		self.showImg = 0
		#colorMode(HSB, 100);
		#tint(0,0)
		#adjust contrast
		#img.adjust.contrast(g, 2)
		#flip the image?
		if self.flipImage:
			rotate(180)
		#self.clearPhotos()
		self.performOCR()
		self.words = self.parseWords()
		self.generator.setWords(words=self.words)
		
	def stop(self):
		self.reset()
		self.loading=0
		if self.makePoems:
			self.lightOn = True
			self.makePoems = False
		#kill any running threads
		if self.thread:
			self.thread._Thread__stop()

	def reset(self):
		#clear the terminal
		os.system('cls' if os.name=='nt' else 'clear')

illuminate = Illuminate()

illuminate.setup();

print 'Number of arguments:', len(sys.argv), 'arguments.'
print 'Argument List:', str(sys.argv)

