	


book.txt:chapter1.txt chapter2.txt chapter3.txt cover.txt
	cat cover.txt chapter1.txt chapter2.txt chapter3.txt > book.txt
	

cover.txt: # if cover is missing create a default cover
	echo " ============Book Cover================\n\
                 Book Logo  "\
	> cover.txt
