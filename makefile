the_image.png: imagecode
	./imagecode
	convert the_image.ppm the_image.png

imagecode: imagecode.c
	gcc -o imagecode imagecode.c


display: the_image.png
	display the_image.png

clean:
	rm imagecode
	rm *.ppm
	rm *.png
	rm *~
