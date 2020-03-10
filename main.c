/******************************************************************************

                            Made by Alex Raborn
                Dr. Linken shows a flow chart, I create a program.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
//variables
//katz - if katz applies for search
//warrant - if warrant issued; 1 = no 2 = yes
//warrant_stand - valid or invalid 1 = valid 2 = invalid
//search - type of search 1 = Terry 2 = Incident to Arrest
//reach - if search was within reach
//space - validly in a space 1 = Yes 2 = No
//exception - exclusionary rule exceptions
//herring - abuse of exception

int
main ()
{
//set variables
  int warrant = 0;
  int katz = 0;
  int warrant_stand = 0;
  int search = 0;
  int reach = 0;
  int space = 0;
  int exception = 0;
  int herring = 0;

//start 
puts("Understanding if the evidence you collected during a search is consistent with the Fourth Amendment can be difficult.");
puts("Use this program to help you figure out- using SCOTUS precedent- if the evidence is admissible in court.\n");

//ask warrant
  puts ("Do you have a warrant?");
  puts ("1 - Yes\n2 - No");
  scanf ("%i", &warrant);

    //don't have a warrant
    switch(warrant) {
    case 2:
      puts("What kind of search was performed? Please enter the number corresponding.");
      puts("1 - Terry Frisk\n2 - Incident to Arrest\n3 - Neither");
      scanf ("%i", &search);
      //terry frisk search
      switch (search) {
        case 1: 
	    puts("You indicated a Terry Frisk was performed.");
	    puts("Your search is permitted via Terry v. Ohio (1968)\n");
        break;
      //incident to arrest search
        case 2:
	    puts("You indicated your search was incident to the arrest of the defendant.");
	    puts("Was the search performed within the area the defendant could reach?");
	    puts("1 - Yes\n2 - No");
	    scanf ("%i", &reach);
	    //search within reach
	    switch (reach) {
	    case 1: 
	      puts("You indicated the search was performed within the reach of the defendant.");
	      puts("Your search is permitted via Arizona v. Gant (2009)");
	      break;
	    //search not within reach
	    case 2:
	      katz = 1;
	      break;
	    }
       
      //bad search
      case 3:
        katz = 1;
        break;
      }
      break;
    //have a warrant
    case 1: 
      puts("Was your warrant valid?");
      puts("1 - Yes\n2 - No");
      scanf ("%i", &warrant_stand);
      //valid warrant
    switch (warrant_stand) {
        case 1:
	        puts("Was your search performed within the confines defined by the warrant?");
	        puts("AKA were you NOT looking for a dead body in a sock drawer?");
	        puts("1 - Yes\n2 - No");
	        scanf ("%i", &space);
	    //validly in space
	        switch (space) {
	        case 1:
	            puts("Congrats! You can use the evidence against the defendant.\n");
	            break;
	        case 2:
	            katz = 1;
	            break;
	        }
	        break;
	  //warrant not valid
	    case 2: 
	        katz = 1;
	        break;
	  }
	  break;
    }

    //warrentless searches
    switch (katz) {
      case 1: 
      puts("According to Katz v. US (1967), warrantless searches are pe se unreasonable.");
      puts("Thanks to Weeks v. US (1914) and Mapp v. Ohio (1961), the fruit of unreasonable searches is not admissible in court.");
      puts("However, there are some exceptions -- it wouldn't be SCOTUS without them.\n");
      //exceptions
      puts("Does your case fit any of these exceptions?");
      puts("1 -- exclusionary rule does not apply to grand jury investigations\n");
      puts("2 -- police acted in good faith\n");
      puts("3 -- discovering the evidence was inevitable\n");
      puts("4 -- honest error by court records\n");
      puts("5 -- knock and announce procedure violated\n");
      puts("6 -- honest error by police\n");
      puts("7 -- No\n");
      scanf ("%i", &exception);
      //exception identified
      //if (exception = 7) {
       // puts("Sorry! You have lost the ability to use that evidence in court. Have fun with that.\n");
     // }
      if (exception != 7) {
	    //abuse of exception?
	    puts("Is the exception being abused?");
	    puts("1 - Yes, lol\n2 - No! Never!");
	    scanf("%i", &herring);
	    //no abuse of exception
	    switch (herring) {
	    case 2:
	      //switch for each exception
	      switch(exception) {
		  case 1:
		    puts("Congrats! According to US v. Calandra (1974), your evidence is admissible in court!\n");
		    break;
		  case 2:
		    puts("Congrats! According to US v. Leon (1984), your evidence is admissible in court!\n");
		    break;
		  case 3:
		    puts("Congrats! According to Nix v. Williams (1984), your evidence is admissible in court!\n");
		    break;
		  case 4:
		    puts("Congrats! According to Arizona v. Evans (1995), your evidence is admissible in court!\n");
		    break;
	      case 5:
		    puts("Congrats! According to Hudson v. Michigan (2006), your evidence is admissible in court!\n");
		    break;
		  case 6:
		    puts("Congrats! According to Herring v. US (2009), your evidence is admissible in court!\n");
		    break;
	      break;
	    }
	    case 1: 
	        puts("Sorry! You have lost the ability to use that evidence in court. Have fun with that.\n");
	        break;
      }
      }
      else if (exception = 7) {
          puts("Sorry! You have lost the ability to use that evidence in court. Have fun with that.\n");
      }
    }
  return 0;
}
