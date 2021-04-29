
book.txt: index.txt chapter1.txt chapter2.txt chapter3.txt
	cat chapter1.txt chapter2.txt chapter3.txt > book.txt

index.txt: chapter1.txt chapter2.txt chapter3.txt lastpage.txt
	echo  " \n  Moby dick - The Whale \n" > index.txt		# Index Title
	head -1 --quiet chapter1.txt chapter2.txt chapter3.txt >> index.txt	# Build Index	
	head -9 --quiet lastpage.txt >> index.txt  # Append Epilog             
