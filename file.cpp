#include "file.h"

void clear_buffer()
{ char c;
  while (c!='\n') c=getchar();
}

int read_std_input(char *w,int size)
{
	fgets(w,size+1,stdin);
	if(strlen(w)>=size)
		{
			clear_buffer();
			//strcat(w,"\n");
			return(1);
		}
	else
		{
  			if(strlen(w)==1)
  					return(0);
		}
	return(-1);
}



    fichier::fichier()
    {
        fp=NULL;
        strcpy(name,"NULL");
        strcpy(mode,"NULL");
    }

    fichier::fichier(char*Name,char*Mode,int Size_len)
    {
        strcpy(name,Name);
        strcpy(mode,Mode);
        size_len=Size_len;
        if(!(fp=fopen(name,mode)))
            {
                cout<<"** Erreur d'initialisation du fichier \n";
                exit(0);
            }
    }

    fichier::~fichier()
    {
    	if(fp)
        fclose(fp);
    }

    void fichier::set_name(const char* Name)
    {
        strcpy(name,Name);
    }
    void fichier::set_mode(const char *Mode)
    {
        strcpy(mode,Mode);
    }
    void fichier::set_size_len(int Size_len)
    {
        size_len=Size_len;
    }
    void fichier::set_fp(FILE *fp)
     {
     	this->fp=fp;
     }
    const char* fichier::get_name() const
    {
        return(name);
    }
    const char* fichier::get_mode() const
    {
        return(mode);
    }
    const int fichier::get_size_len() const
    {
        return(size_len);
    }
    const FILE * fichier::get_fp() const
    {	
    	rewind(fp);
    	return(fp);
    }
void fichier::write_text()
	{
		char w[size_len+1]; 
		int p;

		  cout <<"** Insertion :'("<<this->name<<")'\n";
		  p=read_std_input(w,size_len);
	  	if(p==1)
	  		{
	  			//fputs(w,fp);
                fprintf(fp,"%s\n",w);
	  			cout <<"(+) "<<w<<"\n";
	  		}
        else if(p==-1)
	  	  		cout <<"(-) "<<w<<"\n";

	}

void fichier::write_string(char *w)
 {
 	if(!strncmp(w,"w",1)) 
 		{
 			cout <<"Vous n'avez pas la permission d'ecriture\n";
 			exit(0);
 		}
 	if(strlen(w)==size_len-1)
 		{
 			//fputs(w,fp);
 			//fputs("\n",fp);
            fprintf(fp,"%s\n",w);
 		}	

 }



     void fichier::read_ligne_file( char *w)
    	{
        	 if(!fgets(w,size_len,fp))
        	{
           	 cout<<"** Vous n'avez pas la permission de lecture\n";
           	 exit(0);
        	}
        		cout<<"* "<<w<<"\n";
    	}

    void fichier::create_file(int size_len)
    	{
        	char Name[20];
        	char Mode[3];
        	cout<<"* Nom: \n";cin>>Name;
        	cout<<"* Mode: \n";cin>>Mode;
        	this->size_len=size_len;
         	if(!(fp=fopen(Name,Mode)))
            	{
                	cout<<"* Erreur d'initialisation du fichier\n";
                	exit(0);
           		 }
    	}	

    int fichier::view_file()
     {
 		char w[size_len+1];
 		rewind (fp);
 		if (!fp) return(0);
 		while(fgets(w,size_len+1,fp))
 			cout<<w;
 		return(1);
	 }

	 fichier & fichier::operator+ (const fichier &file)
	  {	  	 
	  	 		fichier *f; FILE *fp_temp;char w[size_len];
	  			f=(fichier*)malloc(sizeof(fichier));
	  			f->create_file(get_size_len());
	  			fp_temp=(FILE*)file.get_fp();
	  			
	  			rewind(this->fp);
				while(fgets(w,size_len,this->fp))
					f->write_string(w);

				while(fgets(w,size_len,fp_temp))
					f->write_string(w);
				
	  	return(*f);

	  }