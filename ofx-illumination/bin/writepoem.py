"""
  illumination.py
  
  by Jack Kalish and Yonatan Ben-Simhon
  Originally developed at NYU ITP 2011

  This is just the stand-alone poetry generator script.
  It takes as input a string of text, and generates a string of word indeces representing the generated poem.
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
		numLines = round(random.random()*11)+3
		print "it will be ",
		print numLines,
		print "lines long"
		print "***START***"
		lines =  self.generator.generateFromText(int(numLines))
		self.lines = lines
		#print lines

		#save poem as string of indeces
		poem = ""
		for line in lines:
			for i in line:
				poem += str(i) + " "
				print self.words[i],
			poem += "-1 " #-1 signifies a new line in the poem
			print 

		print "***END***"
		#print poem

		#write poem to file
		text_file = open("data/poem.txt", "w")
		n = text_file.write(poem)
		text_file.close()

		
	def setWords(self, words):
		self.words = words;
		self.generator.setWords(words)
		
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

#split by space to make words array
words = sys.argv[1].split()
illuminate.setWords(words)
illuminate.makeNewPoem()

