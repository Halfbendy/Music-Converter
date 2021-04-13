//Louis-Marie H Mondesir
//U04822197
//A runner program that turns text file into audio file

#include "song.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cctype>
#include<string>

Song :: Song(const string& file)
   {
      //cout << "Song";
   
      ifstream input;
      
      //istringstream inputLine;
      
      int fileTempo;
      
      string tempInput;
      
      Voice voiceElement;
      
      double Default_Volume = 1000.0;
      
      instrument_t Default_Instrument = ORGAN;
      
      input.open(file);
      
      input >> fileTempo;
      
      setTempo(fileTempo);
      
      //cout << "Tempo: " << tempo <<endl;
      
      getline(input,tempInput);
      
      while (getline(input,tempInput))
         {
      
              //inputLine.str(tempInput);
            
              //cout << "Current Input: " << tempInput << endl;
           
              /*while (inputLine >> tempNote)
                  {
                     cout << "Before Note Submission: " << tempNote << endl;
                  
                     Note(tempNote);
                     
                     
                  
                     //cout << "Left Note" << endl;
               
                  }*/
             
              voiceElement = Voice(tempInput, Default_Volume, Default_Instrument);
              
              addVoice(voiceElement);

         }      
      
   
   }
   
   
Voice::Voice(const string& str, double vol, instrument_t instr)
   {
      istringstream inputLine;
   
      string tempNote;
      
      //Note noteValue;
      
      //Note *noteValuePointer = &noteValue;
      
      inputLine.str(str);
            
      //cout << "Current Input: " << str << endl;
      
      setVolume(vol);
      
      setInstrument(instr);
      
      Note notesElement;
      
      //vector<Note> notes;
      
      //int i;
           
      while (inputLine >> tempNote)
         {
            //cout << "Before Note Submission: " << tempNote << endl;
            
            notesElement = Note((string)tempNote);
            
            //cout << "Note: "<< notesElement.getPitch() << endl;
            
            //notes.push_back(notesElement);
            
            addNote(notesElement);
            
            //cout << "Note: " << notes.at(i).getPitch() << endl;
            
            //i++;

          }
      
             

   }
   
   
Note :: Note(string str)
   {
      string tempPitch;
      
      string tempPitch2 = "KL";
      
      int tempOctave;
      
      char tempDuration;
      
      if (str.size() == 3)
         {
            //cout << "Note size is: 3" << endl; 
            
            tempPitch = str.at(0);
            
            if (tempPitch.compare("R") == 0)
               {
                  pitch = REST;
               }
            else if (tempPitch.compare("A") == 0)
               {
                  pitch = A;
               }
            else if (tempPitch.compare("B") == 0)
               {
                   pitch = B;
               }
            else if (tempPitch.compare("C") == 0)
               {
                   pitch = C;
               }
             else if (tempPitch.compare("D") == 0)
               {
                   pitch = D;
               }
             else if (tempPitch.compare("E") == 0)
               {
                   pitch = E;
               }
             else if (tempPitch.compare("F") == 0)
               {
                   pitch = F;
               }
             else if (tempPitch.compare("G") == 0)
               {
                  pitch = G;
               }
               
               
             tempOctave = str.at(1);
             octave = tempOctave - 48;
             
             tempDuration = str.at(2);
             
             switch (tempDuration)
               {
                  case 113:
                     duration = 1;
                     break;
                  case 104:
                     duration = 2;
                     break;
                  case 119:
                     duration = 4;
                     break;
                  case 101:
                     duration = .5;
                     break;
                  case 115:
                     duration = .25;
                     break;          
               }
  
         
         }
         
       else if (str.size() == 5)
         {
            tempPitch2.at(0) = str.at(0);
            tempPitch2.at(1) = str.at(1);
 
            if (tempPitch2.compare("Db") == 0)
               {
                  pitch = Db; 
               }
            else if (tempPitch2.compare("Eb") == 0)
               {
                  pitch = Eb;
               }
            else if (tempPitch2.compare("Gb") == 0)
               {
                  pitch = Gb;
               }
            else if (tempPitch2.compare("Ab") == 0)
               {
                  pitch = Ab;
               }
            else if (tempPitch2.compare("Bb") == 0)
               {
                  pitch = Bb;
               }
            else if (tempPitch2.compare("A#") == 0)
               {
                  pitch = Bb;
               }
            else if (tempPitch2.compare("C#") == 0)
               {
                  pitch = Db;
               }
            else if (tempPitch2.compare("D#") == 0)
               {
                  pitch = Eb;
               }
            else if (tempPitch2.compare("F#") == 0)
               {
                  pitch = Gb;
               }
            else if (tempPitch2.compare("G#") == 0)
               {
                  pitch = Ab;
               }
               
            tempOctave = str.at(2);
            octave = tempOctave - 48;
            
            tempDuration = str.at(3);
            
            switch (tempDuration)
               {
                  case 113:
                     duration = 1*1.5;
                     break;
                  case 104:
                     duration = 2*1.5;
                     break;
                  case 119:
                     duration = 4*1.5;
                     break;
                  case 101:
                     duration = .5*1.5;
                     break;
                  case 115:
                     duration = .25*1.5;
                     break;          
               } 
  
         }  
         
       else if (str.size() == 4)
         {
            if (isdigit(str.at(2)))
               {
                  tempPitch2.at(0) = str.at(0);
                  tempPitch2.at(1) = str.at(1);

                  if (tempPitch2.compare("Db") == 0)
                     {
                        pitch = Db; 
                     }
                  else if (tempPitch2.compare("Eb") == 0)
                     {
                        pitch = Eb;
                     }
                  else if (tempPitch2.compare("Gb") == 0)
                     {
                        pitch = Gb;
                     }
                  else if (tempPitch2.compare("Ab") == 0)
                     {
                        pitch = Ab;
                     }
                  else if (tempPitch2.compare("Bb") == 0)
                     {
                        pitch = Bb;
                     }
                  else if (tempPitch2.compare("A#") == 0)
                     {
                        pitch = Bb;
                     }
                  else if (tempPitch2.compare("C#") == 0)
                     {
                        pitch = Db;
                     }
                  else if (tempPitch2.compare("D#") == 0)
                     {
                        pitch = Eb;
                     }
                  else if (tempPitch2.compare("F#") == 0)
                     {
                        pitch = Gb;
                     }
                  else if (tempPitch2.compare("G#") == 0)
                     {
                        pitch = Ab;
                     }               
                  
                  tempOctave = str.at(2);
                  octave = tempOctave -48;
                  
                  tempDuration = str.at(3);

                  switch(tempDuration)
                     {
                        case 113:
                           duration = 1;
                           break;
                        case 104:
                           duration = 2;
                           break;
                        case 119:
                           duration = 4;
                           break;
                        case 101:
                           duration = .5;
                           break;
                        case 115:
                           duration = .25;
                           break;          
                     }       
                  
                  
               }
         
            else 
               {
                  tempPitch = str.at(0);
                
                  if (tempPitch.compare("R") == 0)
                     {
                        pitch = REST;
                     }
                  else if (tempPitch.compare("A") == 0)
                     {
                        pitch = A;
                     }
                  else if (tempPitch.compare("B") == 0)
                     {
                         pitch = B;
                     }
                  else if (tempPitch.compare("C") == 0)
                     {
                         pitch = C;
                     }
                   else if (tempPitch.compare("D") == 0)
                     {
                         pitch = D;
                     }
                   else if (tempPitch.compare("E") == 0)
                     {
                         pitch = E;
                     }
                   else if (tempPitch.compare("F") == 0)
                     {
                         pitch = F;
                     }
                   else if (tempPitch.compare("G") == 0)
                     {
                        pitch = G;
                     }
                  
                  tempOctave = str.at(1);
                  octave = tempOctave - 48;
             
                  tempDuration = str.at(2);
             
                  switch (tempDuration)
                    {
                       case 113:
                          duration = 1*1.5;
                          break;
                       case 104:
                          duration = 2*1.5;
                          break;
                       case 119:
                          duration = 4*1.5;
                          break;
                       case 101:
                          duration = .5*1.5;
                          break;
                       case 115:
                          duration = .25*1.5;
                          break;          
                  }                     
 
               }
         
         }
         
       //cout << "Pitch: " << getPitch() << " Octave: " << getOctave() << " Duration: " << getDuration() << endl;
       
         
   }

ostream& operator<<(ostream& out, const Note& n)
   {
      pitch_t outPitch = n.getPitch(); 
      unsigned outOctaveFinal = n.getOctave();
      double outDuration = n.getDuration();
      
      int outPitchCheck = outPitch;
      string outPitchFinal;
      
      string outDurationFinal;
      
      
      //out << "Pitch: " << outPitchCheck << endl;   

      switch(outPitchCheck)
         {
            case 0:
               outPitchFinal = "C";
               break;
            case 1:
               outPitchFinal = "Db";
               break;
            case 2:
               outPitchFinal = "D";
               break;
            case 3:
               outPitchFinal = "Eb";
               break;
            case 4: 
               outPitchFinal = "E";
               break;
            case 5: 
               outPitchFinal = "F";
               break;
            case 6:
               outPitchFinal = "Gb";
               break;
            case 7: 
               outPitchFinal = "G";
               break;
            case 8:
               outPitchFinal = "Ab";
               break;
            case 9:
               outPitchFinal = "A";
               break;
            case 10:
               outPitchFinal = "Bb";
               break;
            case 11:
               outPitchFinal = "B";
               break;
            case 12:
               outPitchFinal = "R";
               break;
         } 
         
      if (outDuration == 1)
         {
            outDurationFinal = "q";
         }
      else if (outDuration == 1.5)
         {
            outDurationFinal = "q.";
         }
      else if (outDuration == 2)
         {
            outDurationFinal = "h";
         }
      else if (outDuration == 3)
         {
            outDurationFinal = "h.";
         }
      else if (outDuration == 4)
         {
            outDurationFinal = "w";
         }
      else if(outDuration == 6)
         {
            outDurationFinal = "w.";
         }
      else if (outDuration == 0.5)
         {
            outDurationFinal = "e";
         }
      else if (outDuration == 0.75)
         {
            outDurationFinal = "e.";
         }
      else if (outDuration == 0.25)
         {
            outDurationFinal = "s";
         }
      else if (outDuration == 0.375)
         {
            outDurationFinal = "s.";
         }    
         
         
      //out << "Made into Notes" << endl;
      
      
      
      out << outPitchFinal << outOctaveFinal << outDurationFinal;
   
      return out;
   }
   
ostream& operator<<(ostream& out, const Voice& v)
   {
      vector<Note> notes = v.getNotes();
      
      for (int i = 0; i < notes.size(); i++)
         {
            out << notes.at(i) << " ";
         }
         
      return out;
   }

ostream& operator<<(ostream& out, const Song& s)

   {
      
      vector<Voice> voice = s.getVoices();
      
      out << s.getTempo() << endl;
      
      for (int i = 0; i < voice.size(); i++)
         {
            out << voice.at(i) << endl;     
         }
      
      
      return out;
   }