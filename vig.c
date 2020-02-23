#include <stdio.h>


//lets crack the vigenere cipher!
int main(){

	//create string for cryptext
	char ct[] = "LAVHEBSJMDINFGXCLWTUUWARWBQWFTEHWUDDTCAAKKTXTSMYALMVHTAHJHKICFAFZKLEXATXIXYMFVLVGUDALRFJTTGKXNLOYOWLVVVQAFKVGEZLEHEXHEZGPVZEDOWARZEAFSGVASOSDXJIEZESBEWTDWSFGVOPMUMJENPKWKMMCQKVXJMGZWVBEEWMQLARXGUNWLLWEDKKHCICAFLKFPOHWJTTGEEKLHKLEUJVTKEAESJXJYLFDSPVRFAJUXDINFAKLFQEFAEXJYNMTDXKSRQUGOVVTTWUHEXEZLGYVPEOLJHEMCOGEFLRIOSLBFRSRJGFKLEFWUAESLAYQIISVUVWKVZEZAFKVWPAFKXKSAOGMKKSRPWJHIHUXQSNKLODARXUAADJSGKMSEMWWSCARWVXIELVMVZVJODWPTDTLQESGPGOYEMGZGAFAGGJWEDNAVVWNAOWGTVYBLUXIXAUFUHDQUZAUTKMOZKTRUIFMMDMNMTTLZXBIYZWUXJWADQLHUICDQHMKLEOGEFLRIOSLBFRSEGDXCCIZLZXYENPKGYKLEQFVNJIRFZALRTPXAWLSSTTOZXEXHQVSMRMSUFEHKMOZGNXIILQULKFRIOFWMNSRWKGKRXRQKLHEENQDWVKVOZAUWVZIOWAYKLEOGEFLRIOSLBFRSBJGOZHEDAKLVVVQVOBKLAISJKRRTEWWDZRGFZGLVGOYEMGZGAFAGGJXHQHJHMMDQJUTEROFHJHMMDQLZXUETMTWVRYSQALARWDQKAZEIDFZWMVGHZGDHXCSGUZMYETULUTEROFTWTTGEEKWWSCAZQLAZVDBSJMPAEPGFHKLAHWSGPWIXNWKSYLXWLLRRDFZWWZWCGKKBFRSIALAZRTTWWQVGUFANXSVAZUZTIISFADEFRGAAFZNLIXWLAVVETSKGFXYQLTXVRAPWUBJMOZOZXKLEDLGLVIKXWYBJPAFAGGNIMGKLPFVKIALATSNSJWLJMNPMKMICAOSVXDMCEHJBMECKYJHLTSMFVHKLEDKLHTVARLSGRTPDGSVYXHMLSWUVEEKWLRPLAXLAVQUXLAICICAEHXKMNSUGGTIRZKLARXHMNWUVINFZWYFGUEGXLFQUOZVXSETQTMMNICMFSECEGDWWMYETIWOBCPNQWVHEKOUFYAFREELSGUMNRGJFVHPGTDBTHENSLXRFOGLZHNFEELLHGVOFWUMCMBQJLRRRDEWUNIMTKAFUFXHAMJERASMFVHLVTQUZGFPOSQ";
	
	//convert cryptext to Z_26
	//determine length of cryptext
	int n = sizeof(ct)/sizeof(ct[0])-1;
	int y[n];
	int i;
	for (i = 0; i < n; ++i){
		if (ct[i] >= 'A' && ct[i] <= 'Z')	//check that it's a capital letter betwen A and Z
			y[i] = ct[i] - 'A';		//make the character the z_26 value of itself
	}

	//split the cryptext into m substrings
	//start with 4 and go through to 8
	int m = 4;
       	while (m < 9){
	
		//new size of substrings
        	int size = n / m;	//m=8 results in 157.5
		int y1[size];				//first of the substrings, use 4 then 5 all the wy til al 8 are used
	        int y2[size];
	        int y3[size];
        	int y4[size];
                int y5[size];
                int y6[size];
                int y7[size];
                int y8[size];
		


		if (m == 4){

			for (i = 0; i < size; ++i){
				if (i*m < n)
					y1[i] = y[i*m];
				if ((i*m)+1 < n)
					y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
        	                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                	                y4[i] = y[(i*m)+3];
			}
			printf("m = %d \n", m);
			float f[26];	//frequency
			for (i = 0; i < 26; ++i)
        		        f[i] = 0;       //fill with zeroes
			for (i = 0; i < size; ++i){
				int j;
				for (j = 0; j < 26; ++j){	//count frequency
               				if (j == y1[i])         
						f[j]++;    
        			}
			}
			float ioc1 = 0;
    			    for (i = 0; i < 26; ++i){	//cakcykate index of coincidence  
				ioc1 += f[i]*(f[i]-1);
			}		
			ioc1 /= size*(size-1);
			printf("Ic(y1) = %f \n", ioc1);	//print first arrays index of coincidence

			// now the other three	
			for (i = 0; i < 26; ++i)
                		f[i] = 0;       
			for (i = 0; i < size; ++i){
            			int j;
				for (j = 0; j < 26; ++j){
                			if (j == y2[i])
                    				f[j]++;
            			}
        		}
			float ioc2 = 0;
        		for (i = 0; i < 26; ++i){
				ioc2 += f[i]*(f[i]-1);
			}
			ioc2 /= size*(size-1);
			printf("Ic(y2) = %f \n", ioc2);


			
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
				for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float ioc3 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc3 += f[i]*(f[i]-1);
                        }
                        ioc3 /= size*(size-1);
                        printf("Ic(y3) = %f \n", ioc3);
        		

		
			for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
				for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float ioc4 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc4 += f[i]*(f[i]-1);
                        }
                        ioc4 /= size*(size-1);
                        printf("Ic(y4) = %f \n", ioc4);

                        


		}
		//repeat the same process for all substrings of m=5 through 8
		if (m == 5){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m];
                                if ((i*m)+1 < n)
                                        y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
                                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                                        y4[i] = y[(i*m)+3];
                                if ((i*m)+4 < n)
                                        y5[i] = y[(i*m)+4];
                        }
                        printf("m = %d \n", m);
                        float f[26];
			for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y1[i])
                                                f[j]++;
                                }
                        }
                        float ioc1 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc1 += f[i]*(f[i]-1);
                        }
                        ioc1 /= size*(size-1);
                        printf("Ic(y1) = %f \n", ioc1);

			
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y2[i])
                                                f[j]++;
                                }
                        }
                        float ioc2 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc2 += f[i]*(f[i]-1);
                        }
                        ioc2 /= size*(size-1);
                        printf("Ic(y2) = %f \n", ioc2);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float ioc3 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc3 += f[i]*(f[i]-1);
                        }
                        ioc3 /= size*(size-1);
                        printf("Ic(y3) = %f \n", ioc3);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float ioc4 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc4 += f[i]*(f[i]-1);
                        }
                        ioc4 /= size*(size-1);
                        printf("Ic(y4) = %f \n", ioc4);


			for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y5[i])
                                                f[j]++;
                                }
                        }
                        float ioc5 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc5 += f[i]*(f[i]-1);
                        }
                        ioc5 /= size*(size-1);
                        printf("Ic(y5) = %f \n", ioc5);







                }

		if (m == 6){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m];
                                if ((i*m)+1 < n)
                                        y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
                                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                                        y4[i] = y[(i*m)+3];
                                if ((i*m)+4 < n)
                                        y5[i] = y[(i*m)+4];
				if ((i*m)+5 < n)
                                        y6[i] = y[(i*m)+5];
                        }
			
                        printf("m = %d \n", m);
                        float f[26];
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y1[i])
                                                f[j]++;
                                }
                        }
                        float ioc1 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc1 += f[i]*(f[i]-1);
                        }
                        ioc1 /= size*(size-1);
                        printf("Ic(y1) = %f \n", ioc1);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y2[i])
                                                f[j]++;
                                }
                        }
                        float ioc2 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc2 += f[i]*(f[i]-1);
                        }
                        ioc2 /= size*(size-1);
                        printf("Ic(y2) = %f \n", ioc2);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float ioc3 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc3 += f[i]*(f[i]-1);
                        }
                        ioc3 /= size*(size-1);
                        printf("Ic(y3) = %f \n", ioc3);

			

                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float ioc4 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc4 += f[i]*(f[i]-1);
                        }
                        ioc4 /= size*(size-1);
                        printf("Ic(y4) = %f \n", ioc4);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y5[i])
                                                f[j]++;
                                }
                        }
                        float ioc5 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc5 += f[i]*(f[i]-1);
                        }
                        ioc5 /= size*(size-1);
                        printf("Ic(y5) = %f \n", ioc5);



			for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y6[i])
                                                f[j]++;
                                }
                        }
                        float ioc6 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc6 += f[i]*(f[i]-1);
                        }
                        ioc6 /= size*(size-1);
                        printf("Ic(y6) = %f \n", ioc6);


                }

		if (m == 7){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m];
                                if ((i*m)+1 < n)
                                        y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
                                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                                        y4[i] = y[(i*m)+3];
                                if ((i*m)+4 < n)
                                        y5[i] = y[(i*m)+4];
                                if ((i*m)+5 < n)
                                        y6[i] = y[(i*m)+5];
				if ((i*m)+6 < n)
                                        y7[i] = y[(i*m)+6];
                        }

                        printf("m = %d \n", m);
                        float f[26];
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y1[i])
                                                f[j]++;
                                }
                        }
                        float ioc1 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc1 += f[i]*(f[i]-1);
                        }
                        ioc1 /= size*(size-1);
                        printf("Ic(y1) = %f \n", ioc1);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y2[i])
                                                f[j]++;
                                }
                        }
                        float ioc2 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc2 += f[i]*(f[i]-1);
                        }
                        ioc2 /= size*(size-1);
                        printf("Ic(y2) = %f \n", ioc2);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float ioc3 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc3 += f[i]*(f[i]-1);
                        }
                        ioc3 /= size*(size-1);
                        printf("Ic(y3) = %f \n", ioc3);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float ioc4 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc4 += f[i]*(f[i]-1);
                        }
                        ioc4 /= size*(size-1);
                        printf("Ic(y4) = %f \n", ioc4);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y5[i])
                                                f[j]++;
                                }
                        }
                        float ioc5 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc5 += f[i]*(f[i]-1);
                        }
                        ioc5 /= size*(size-1);
                        printf("Ic(y5) = %f \n", ioc5);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y6[i])
                                                f[j]++;
                                }
                        }
                        float ioc6 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc6 += f[i]*(f[i]-1);
                        }
                        ioc6 /= size*(size-1);
                        printf("Ic(y6) = %f \n", ioc6);



	
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y7[i])
                                                f[j]++;
                                }
                        }
                        float ioc7 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc7 += f[i]*(f[i]-1);
                        }
                        ioc7 /= size*(size-1);
                        printf("Ic(y7) = %f \n", ioc7);

                }

		if (m == 8){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m];
                                if ((i*m)+1 < n)
                                        y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
                                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                                        y4[i] = y[(i*m)+3];
                                if ((i*m)+4 < n)
                                        y5[i] = y[(i*m)+4];
                                if ((i*m)+5 < n)
                                        y6[i] = y[(i*m)+5];
                                if ((i*m)+6 < n)
                                        y7[i] = y[(i*m)+6];
				if ((i*m)+7 < n)
                                        y8[i] = y[(i*m)+7];

                        }

                        printf("m = %d \n", m);
                        float f[26];
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y1[i])
                                                f[j]++;
                                }
                        }
                        float ioc1 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc1 += f[i]*(f[i]-1);
                        }
                        ioc1 /= size*(size-1);
                        printf("Ic(y1) = %f \n", ioc1);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y2[i])
                                                f[j]++;
                                }
                        }
                        float ioc2 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc2 += f[i]*(f[i]-1);
                        }
                        ioc2 /= size*(size-1);
                        printf("Ic(y2) = %f \n", ioc2);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float ioc3 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc3 += f[i]*(f[i]-1);
                        }
                        ioc3 /= size*(size-1);
                        printf("Ic(y3) = %f \n", ioc3);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float ioc4 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc4 += f[i]*(f[i]-1);
                        }
                        ioc4 /= size*(size-1);
                        printf("Ic(y4) = %f \n", ioc4);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y5[i])
                                                f[j]++;
                                }
                        }
                        float ioc5 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc5 += f[i]*(f[i]-1);
                        }
                        ioc5 /= size*(size-1);
                        printf("Ic(y5) = %f \n", ioc5);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y6[i])
                                                f[j]++;
                                }
                        }
                        float ioc6 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc6 += f[i]*(f[i]-1);
                        }
                        ioc6 /= size*(size-1);
                        printf("Ic(y6) = %f \n", ioc6);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y7[i])
                                                f[j]++;
                                }
                        }
                        float ioc7 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc7 += f[i]*(f[i]-1);
                        }
                        ioc7 /= size*(size-1);
                        printf("Ic(y7) = %f \n", ioc7);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y8[i])
                                                f[j]++;
                                }
                        }
                        float ioc8 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc8 += f[i]*(f[i]-1);
                        }
                        ioc8 /= size*(size-1);
                        printf("Ic(y8) = %f \n", ioc8);



                }

		m++;
	}
			
			m = 7;	
                int size = n / m;       //m=8 results in 157.5
                int y1[size];                           //first of the substrings, use 4 then 5 all the wy til al 8 are used
                int y2[size];
                int y3[size];
                int y4[size];
                int y5[size];
                int y6[size];
                int y7[size];

			for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m];
                                if ((i*m)+1 < n)
                                        y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
                                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                                        y4[i] = y[(i*m)+3];
                                if ((i*m)+4 < n)
                                        y5[i] = y[(i*m)+4];
                                if ((i*m)+5 < n)
                                        y6[i] = y[(i*m)+5];
                                if ((i*m)+6 < n)
                                        y7[i] = y[(i*m)+6];
                        }


			//generate Mg table
                        printf("%10d %10d %10d %10d %10d %10d %10d %10d", 0, 1, 2, 3, 4, 5, 6, 7);
                        float f[26];
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y1[i])
                                                f[j]++;
                                }
                        }
                        for (i = 0; i < 26; ++i){
                                ioc1 += f[i]*(f[i]-1);
                        }

                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y2[i])
                                                f[j]++;
                                }
                        }
                        float ioc2 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc2 += f[i]*(f[i]-1);
                        }
                        ioc2 /= size*(size-1);
                        printf("Ic(y2) = %f \n", ioc2);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float ioc3 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc3 += f[i]*(f[i]-1);
                        }
                        ioc3 /= size*(size-1);
                        printf("Ic(y3) = %f \n", ioc3);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float ioc4 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc4 += f[i]*(f[i]-1);
                        }
                        ioc4 /= size*(size-1);
                        printf("Ic(y4) = %f \n", ioc4);


                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y5[i])
                                                f[j]++;
                                }
                        }
                        float ioc5 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc5 += f[i]*(f[i]-1);
                        }
                        ioc5 /= size*(size-1);
                        printf("Ic(y5) = %f \n", ioc5);



                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y6[i])
                                                f[j]++;
                                }
                        }
                        float ioc6 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc6 += f[i]*(f[i]-1);
                        }
                        ioc6 /= size*(size-1);
                        printf("Ic(y6) = %f \n", ioc6);




                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y7[i])
                                                f[j]++;
                                }
                        }
                        float ioc7 = 0;
                        for (i = 0; i < 26; ++i){
                                ioc7 += f[i]*(f[i]-1);
                        }
                        ioc7 /= size*(size-1);
                        printf("Ic(y7) = %f \n", ioc7);




	return 0;
}	
