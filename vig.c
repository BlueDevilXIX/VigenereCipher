#include <stdio.h>


//lets crack the vigenere cipher!
int main(){

	//create string for cryptext
	char ct[] = "LAVHEBSJMDINFGXCLWTUUWARWBQWFTEHWUDDTCAAKKTXTSMYALMVHTAHJHKICFAFZKLEXATXIXYMFVLVGUDALRFJTTGKXNLOYOWLVVVQAFKVGEZLEHEXHEZGPVZEDOWARZEAFSGVASOSDXJIEZESBEWTDWSFGVOPMUMJENPKWKMMCQKVXJMGZWVBEEWMQLARXGUNWLLWEDKKHCICAFLKFPOHWJTTGEEKLHKLEUJVTKEAESJXJYLFDSPVRFAJUXDINFAKLFQEFAEXJYNMTDXKSRQUGOVVTTWUHEXEZLGYVPEOLJHEMCOGEFLRIOSLBFRSRJGFKLEFWUAESLAYQIISVUVWKVZEZAFKVWPAFKXKSAOGMKKSRPWJHIHUXQSNKLODARXUAADJSGKMSEMWWSCARWVXIELVMVZVJODWPTDTLQESGPGOYEMGZGAFAGGJWEDNAVVWNAOWGTVYBLUXIXAUFUHDQUZAUTKMOZKTRUIFMMDMNMTTLZXBIYZWUXJWADQLHUICDQHMKLEOGEFLRIOSLBFRSEGDXCCIZLZXYENPKGYKLEQFVNJIRFZALRTPXAWLSSTTOZXEXHQVSMRMSUFEHKMOZGNXIILQULKFRIOFWMNSRWKGKRXRQKLHEENQDWVKVOZAUWVZIOWAYKLEOGEFLRIOSLBFRSBJGOZHEDAKLVVVQVOBKLAISJKRRTEWWDZRGFZGLVGOYEMGZGAFAGGJXHQHJHMMDQJUTEROFHJHMMDQLZXUETMTWVRYSQALARWDQKAZEIDFZWMVGHZGDHXCSGUZMYETULUTEROFTWTTGEEKWWSCAZQLAZVDBSJMPAEPGFHKLAHWSGPWIXNWKSYLXWLLRRDFZWWZWCGKKBFRSIALAZRTTWWQVGUFANXSVAZUZTIISFADEFRGAAFZNLIXWLAVVETSKGFXYQLTXVRAPWUBJMOZOZXKLEDLGLVIKXWYBJPAFAGGNIMGKLPFVKIALATSNSJWLJMNPMKMICAOSVXDMCEHJBMECKYJHLTSMFVHKLEDKLHTVARLSGRTPDGSVYXHMLSWUVEEKWLRPLAXLAVQUXLAICICAEHXKMNSUGGTIRZKLARXHMNWUVINFZWYFGUEGXLFQUOZVXSETQTMMNICMFSECEGDWWMYETIWOBCPNQWVHEKOUFYAFREELSGUMNRGJFVHPGTDBTHENSLXRFOGLZHNFEELLHGVOFWUMCMBQJLRRRDEWUNIMTKAFUFXHAMJERASMFVHLVTQUZGFPOSQ";

	//convert cryptext to Z_26
	//determine length of cryptext
	int n = sizeof(ct)/sizeof(ct[0]);
	int y[n];
	int i;
	for (i = 0; i < n; ++i){
		if (ct[i] >= 'A' && ct[i] <= 'Z')	//check that it's a capital letter betwen A and Z
			y[i] = ct[i] - 'A';		//make the character the z_26 value of itself
	}


	//split the cryptext into m substrings
	//start with 4 and go through to 8
	int m = 4
       	while (m < 9){
	
		int size = (int) ((float)n / m) + 1;	//new size of substrings
        	int y1[size];				//first of the substrings, use 4 then 5 all the wy til al 8 are used
	        int y2[size];
	        int y3[size];
        	int y4[size];
                int y5[size];
                int y6[size];
                int y7[size];
                int y8[size];
		


		if (m = 4){

			for (i = 0; i < size; ++i){
				if (i*m < n)
					y1[i] = y[i*m]
				if ((i*m)+1 < n)
					y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
        	                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                	                y4[i] = y[(i*m)+3];
			}
			printf("m = %d \n", &m);
			float f[26];	//frequency
			for (i = 0; i < 26; ++i)
        		        f[i] = 0;       //fill with zeroes
			for (i = 0; i < size; ++i){
				for (j = 0; j < 26; ++j){	//count frequency
               				if (j == y1[i])          
                	        		f[j]++;    
        			}
			}
			float ioc1 = 0;
    			    for (i = 0; i < 26; ++i){	//cakcykate percent freq. and index of coincidence
        		        f[i] /= size;  
				ioc1 += f[i]*(f[i]-1);
			}
			ioc1 /= size*(size-1);
			printf("Ic(y1) = %f \n", &ioc1);	//print first arrays index of coincidence

			//now the second third and fourth
			for (i = 0; i < 26; ++i)
                		f[i] = 0;       
			for (i = 0; i < size; ++i){
            			for (j = 0; j < 26; ++j){
                			if (j == y2[i])
                    				f[j]++;
            			}
        		}
			float ioc2 = 0;
        		for (i = 0; i < 26; ++i){}
        		        f[i] /= size;  
				ioc2 += f[i]*(f[i]-1);
			}
			ioc2 /= size*(size-1);
			printf("Ic(y2) = %f \n", &ioc2);


			//y3
                        for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                for (j = 0; j < 26; ++j){
                                        if (j == y3[i])
                                                f[j]++;
                                }
                        }
                        float ioc3 = 0;
                        for (i = 0; i < 26; ++i){}
                                f[i] /= size;
                                ioc3 += f[i]*(f[i]-1);
                        }
                        ioc3 /= size*(size-1);
                        printf("Ic(y3) = %f \n", &ioc3);
        		

			//y4
			for (i = 0; i < 26; ++i)
                                f[i] = 0;
                        for (i = 0; i < size; ++i){
                                for (j = 0; j < 26; ++j){
                                        if (j == y4[i])
                                                f[j]++;
                                }
                        }
                        float ioc4 = 0;
                        for (i = 0; i < 26; ++i){}
                                f[i] /= size;
                                ioc4 += f[i]*(f[i]-1);
                        }
                        ioc4 /= size*(size-1);
                        printf("Ic(y4) = %f \n", &ioc4);

		}
		
		if (m = 5){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m]
                                if ((i*m)+1 < n)
                                        y2[i] = y[(i*m)+1];
                                if ((i*m)+2 < n)
                                        y3[i] = y[(i*m)+2];
                                if ((i*m)+3 < n)
                                        y4[i] = y[(i*m)+3];
                                if ((i*m)+4 < n)
                                        y5[i] = y[(i*m)+4];

                        }
                }

		if (m = 6){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m]
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
                }

		if (m = 7){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m]
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
                }

		if (m = 8){
                        for (i = 0; i < size; ++i){
                                if (i*m < n)
                                        y1[i] = y[i*m]
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
                }




	}

	


	return 0;
}	
