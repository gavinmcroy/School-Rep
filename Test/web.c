
// -----------------------------------
// CSCI 340 - Operating Systems
// Fall 2022
// web.c header file
// 
// Homework 3
//
// -----------------------------------

#include <string.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "web.h"

int write_url_file( char* file_path, web_t* web_array, int num_urls );

// global variable used by the write_callback function
size_t length = 0;


// ------------------------------------
// Function prototype that is used by the curl library to
// retrieve the webpage (in the response message) and 
// store in the web_t webpage field.
// 
//
// Arguments:	web_t pointer
//
// Return:     	OK on success, FAIL on error
//

size_t write_callback(void *ptr, size_t size, size_t nmemb, char** buffer ) {

	// -------------------------------------
	// Please do not modify this code
	// -------------------------------------

	*buffer = (char*)realloc( *buffer, ( length + size*nmemb )*sizeof( char* ) ); 

	strcat( *buffer, (char*) ptr );

	length += (size*nmemb);

	return size * nmemb;

} // end write_callback function

// ------------------------------------
// Function prototype that connects to the web address 
// specified in the web_t url field and retrieves
// the html webpage (using the curl c-library)
// 
//
// Arguments:	web_t pointer
//
// Return:     	OK on success, FAIL on error
//

int get_webpage( web_t* web_struct ) {

	// -------------------------------------
	// Please do not modify this code
	// -------------------------------------

	CURL *curl;
  	CURLcode error_code = FAIL;

	length = 0;

  	curl = curl_easy_init();

  	if ( curl ) {

	    	web_struct->webpage = malloc( sizeof( char ) * length );

	    	curl_easy_setopt(curl, CURLOPT_URL, web_struct->url );
	    	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	    	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	    	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &web_struct->webpage );
	 
	    	error_code = curl_easy_perform( curl );

		curl_easy_cleanup( curl );

	}
    
	return ( error_code == OK ) ? OK : FAIL;

} // end get_response function



// ------------------------------------
// Function prototype that parses webpage/URL 
// pointed at by client socket
// 
//
// Arguments:	web_t pointer
//
// Return:     	OK on success, FAIL on error
//
void parse( web_t* web_struct ) {

	
	// -----------------------------------------
	// TODO:
	// -----------------------------------------
	//
	// Parse the webpage field in the web_t stuct
	// looking for each href attribute value that
	// has the word "trump" (not case-sensitive)
	// in the string.
	//
	// An example (from the usatoday website)
	// href="/story/news/politics/2018/10/23/donald-trump-looks-ahead-life-after-midterms/1732675002/"
	// 
	// If the word "trump" is in the href string, then
	// the entire href string value is added to the links 
	// array and the link_cnt field (also in the web_t struct)
	// is incremented by one.
	// 
	// Pseudocode example,
	// links[ link_cnt++ ]="/story/news/politics/2018/10/23/donald-trump-looks-ahead-life-after-midterms/1732675002/"
	//
	// Note: you will need to malloc the links array
	char* html = web_struct -> webpage;
	char* HrefFound = strstr(html, "href=");
	
	web_struct->links = (char**) malloc(sizeof(char**));
	web_struct->link_cnt = 0;
	
	int counter = 0;
	
	while(HrefFound != NULL){
		char* trump = "trump";
		char* url = (char*) malloc (210 * sizeof(char));
		strncpy(url, HrefFound, 200);
		
		if(strstr(url, trump) != NULL){
			char* HrefTrump;
			
			if(strstr(url, "http") != NULL){
				char* urlTemp = strstr(url, "/");
				
				urlTemp += 3;
				urlTemp = strstr(urlTemp, "/");
				HrefTrump = strstr(urlTemp, "/");
				
				web_struct -> link_cnt++;
				web_struct -> links = (char**) realloc(web_struct -> links, web_struct -> link_cnt * sizeof(char**));
			}
			else{
				HrefTrump = strstr(url, "\"");
				
				web_struct -> link_cnt++;
				web_struct -> links = (char**) realloc(web_struct -> links, web_struct -> link_cnt * sizeof(char**));
			}
			
			char* hold = NULL;
			char* tok = strtok_r(HrefTrump, "\"", &hold);
			char splt[200];
			
			strncpy(splt, tok, strlen(tok));
			splt[strlen(splt) + 1] = '\0';
			
			char* last = (char*)malloc(strlen(splt) * sizeof(char));
			
			strncpy(last, splt, strlen(tok));
			
			web_struct -> links[counter] =  last;
			
			counter++;
			
			if(url) {
				free(url);
			}
		}
		
		HrefFound += 5;
		HrefFound = strstr(HrefFound, "href=");
	}
	
	if(web_struct -> link_cnt == 0){
		free(web_struct -> links);
	}
		

	if ( WEB_DEBUG ) {
		printf("URL=%s\n", web_struct->url ); 
		//printf("CNT=%d\n", web_struct->link_cnt );
		//printf("WEBPAGE=%s\n", web_struct->webpage );
	}
	
	return;

} // end parse function
