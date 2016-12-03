ARCHIVE=dc_examples_cvs
BAKDIR=$(HOME)
BAKDIR2=/mnt/storage/_dc_land

all:
    	
	tar cvf ./$(ARCHIVE).tar *
	gzip $(ARCHIVE).tar
	cp $(ARCHIVE).tar.gz $(BAKDIR)
	mv $(ARCHIVE).tar.gz $(BAKDIR2)
