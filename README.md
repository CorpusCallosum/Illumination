*Version 005 -* updated with support for Tesseract Open Source OCR Engine v3.02.02 with Leptonica


# Illumination
==============

## TO DO
8/15/2020
- implement language detection
- use training data without tagged POS, and ignore POS, to first see if this works at all, before looking into POS tagging in German

7/2/2020
- process german corpus to generate parts of speech to generate the training model
- update markovgenerator-de to detect German parts of speech in source text
- update tesseract to add support for German, and detect language of source text
- install sensors into new clipboard

## Setting up on new computer
- install tesseract
- install additional language training data for tessearct, if other than english
  -  on linux: sudo apt-get install tesseract-ocr-[lang] https://askubuntu.com/questions/793634/how-do-i-install-a-new-language-pack-for-tesseract-on-16-04


## NON-INTERACTIVE VERSION for MADA INSTALLATION

run from console:
java -d32 -jar -Xmx500M processing/processing-py.jar illumination_mada_.py

-------------------
## INTERACTIVE VERSION SETUP INSTRUCTIONS

1. 


## TO CALIBRATE:

1. press "c" to enter calibration mode

2. use arrow keys to align image

3. use [] -= and ,. keys to adjust image scale

4. press "c" again to exit calibration mode

## TO RUN:

1. press [SPACE] to run the OCR, light will begin to flicker

2. wait 1-5 minutes

## Notes
tesseract command to generate hocr file (xml markup)

```tesseract file-name.jpg output-file-name -l eng -psm 1 hocr```

tesseract manual: https://github.com/tesseract-ocr/tesseract/blob/master/doc/tesseract.1.asc

