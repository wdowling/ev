SUBDIRS=sys/boot

kernel:
	$(MAKE) -C sys/boot

clean:
	cd sys/boot; $(MAKE) clean
