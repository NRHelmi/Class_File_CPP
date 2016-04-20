#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

void clear_buffer();
int read_std_input(char*,int);

class fichier
{
	private:
    	char name[20];
    	char mode[5];
    	FILE* fp;
    	int size_len;
	public:
		fichier();
		fichier(char*,char*,int);
		~fichier();
		void set_name(const char*);
		void set_mode(const char*);
		void set_size_len(int);
		void set_fp(FILE*);
	    const char* get_name() const;
		const char* get_mode() const;
		const int get_size_len() const;
		const FILE* get_fp() const;
		void write_text();
		void write_string(char *);
		void read_ligne_file(char*);
		void create_file(int);
		int view_file();
		fichier & operator+(const fichier&);
};
#endif