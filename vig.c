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
                        printf("%10d %10d %10d %10d %10d %10d %10d \n", 1, 2, 3, 4, 5, 6, 7);
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
			//frequency table
			float p[] = {.082, .015, .028, .043, .127, .022, .020, .061, .070, .002, .008, .040, .024, .067, .075, .019, .001, .060, .063, .091, .028, .010, .023, .001, .020, .001};
			float q[26];
			
			
                        for (i = 0; i < 26; ++i){
                                q[i] = f[i] / size;
                        }
			float v[26];
			float mg1[26];
			int g;
			for (g = 0; g < 26; ++g){
				for (i = 0; i < 26; ++i){
					v[i] = q[(i+g)%26];
					mg1[g] += v[i] * p[i];
				}
			}
			
			//repeat for y2 through y7
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y2[i])
                                                f[j]++;
                                }
                        }
                        float q2[26];
                        for (i = 0; i < 26; ++i){
                                q2[i] = f[i] / size;
                        }
                        float v2[26];
                        float mg2[26];
                        for (g = 0; g < 26; ++g){
                                for (i = 0; i < 26; ++i){
                                        v2[i] = q2[(i+g)%26];
                                        mg2[g] += v2[i] * p[i];
                                }
                        }
			

			
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float q3[26];
                        for (i = 0; i < 26; ++i){
                                q3[i] = f[i] / size;
                        }
                        float v3[26];
                        float mg3[26];
                        for (g = 0; g < 26; ++g){
                                for (i = 0; i < 26; ++i){
                                        v3[i] = q3[(i+g)%26];
                                        mg3[g] += v3[i] * p[i];
                                }
                        }






                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float q4[26];
                        for (i = 0; i < 26; ++i){
                                q4[i] = f[i] / size;
                        }
                        float v4[26];
                        float mg4[26];
                        for (g = 0; g < 26; ++g){
                                for (i = 0; i < 26; ++i){
                                        v4[i] = q4[(i+g)%26];
                                        mg4[g] += v4[i] * p[i];
                                }
                        }




                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y5[i])
                                                f[j]++;
                                }
                        }
                        float q5[26];
                        for (i = 0; i < 26; ++i){
                                q5[i] = f[i] / size;
                        }
                        float v5[26];
                        float mg5[26];
                        for (g = 0; g < 26; ++g){
                                for (i = 0; i < 26; ++i){
                                        v5[i] = q5[(i+g)%26];
                                        mg5[g] += v5[i] * p[i];
                                }
                        }





                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y6[i])
                                                f[j]++;
                                }
                        }
                        float q6[26];
                        for (i = 0; i < 26; ++i){
                                q6[i] = f[i] / size;
                        }
                        float v6[26];
                        float mg6[26];
                        for (g = 0; g < 26; ++g){
                                for (i = 0; i < 26; ++i){
                                        v6[i] = q6[(i+g)%26];
                                        mg6[g] += v6[i] * p[i];
                                }
                        }






                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                int j;
                                for (j = 0; j < 26; ++j){
                                        if (j == y7[i])
                                                f[j]++;
                                }
                        }
                        float q7[26];
                        for (i = 0; i < 26; ++i){
                                q7[i] = f[i] / size;
                        }
                        float v7[26];
                        float mg7[26];
                        for (g = 0; g < 26; ++g){
                                for (i = 0; i < 26; ++i){
                                        v7[i] = q7[(i+g)%26];
					mg7[g] += v7[i] * p[i];
                                }
                        }

			//print the table
			char d[] = "Mg";
			printf("g %10s %10s %10s %10s %10s %10s %10s \n", d, d, d, d, d, d, d);
			for (g = 0; g < 26; ++g)
				printf("%.2d %10.4f %10.4f %10.4f %10.4f %10.4f %10.4f %10.4f \n", g, mg1[g], mg2[g], mg3[g], mg4[g], mg5[g], mg6[g], mg7[g]);




	//decipher the cryptext
	int key[] = {18, 19, 17, 4, 0, 12, 18};
	int x[m*size];
	for (i = 0; i < size; ++i){
		x[i*m] = (y1[i] - key[0]+26) % 26;
                x[(i*m)+1] = (y2[i] - key[1]+26) % 26;
                x[(i*m)+2] = (y3[i] - key[2]+26) % 26;
                x[(i*m)+3] = (y4[i] - key[3]+26) % 26;
                x[(i*m)+4] = (y5[i] - key[4]+26) % 26;
                x[(i*m)+5] = (y6[i] - key[5]+26) % 26;
                x[(i*m)+6] = (y7[i] - key[6]+26) % 26;
	}
	//x now holds the integer version of the plaintext
	//lets convert it to a string of letters
	char pt[m*size];
	for (i = 0; i < m*size; ++i){
		if (x[i] >= 0 && x[i] <= 25)       //check that its in z_26
                        pt[i] = x[i] + 'a';             //make the z_26 value a character
        }
	
	printf("%s \n", pt);





		

	return 0;

}
