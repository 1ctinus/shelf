#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
char *price;
 GtkWidget *button;
 static size_t disp(void *buffer,size_t size,size_t nmemb,void *userp){
   //printf("gdsgsdsgdgds%s\n",(char *)buffer);

    const char *PATTERN1 = "\"rate\":\"";
    const char *PATTERN2 = "\",\"description\":\"United";

    char *target = NULL;
    char *start, *end;
    if (( start = strstr( buffer, PATTERN1 ) ))
    {
        start += strlen( PATTERN1 );
        if (( end = strstr( start, PATTERN2 ) ))
        {
            target = ( char * )malloc( end - start + 1 );
            memcpy( target, start, end - start );
            target[end - start] = '\0';
        }
    }
   price = malloc(sizeof(target) + 1);
    if ( target ){ strcpy(price,target);}

    free( target );
       return size * nmemb;
 }
void curl(){
	  CURL *curl;
  CURLcode res;
  //FILE *foo;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.coindesk.com/v1/bpi/currentprice.json");
    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, disp);
 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
   // printf("%s",(char *)foo);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
}

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  curl();
  gtk_label_set_text(GTK_LABEL(button), price);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button_box, *grid, *picardia, *update;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Bitcoin Price");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

 
  //button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  //gtk_container_add (GTK_CONTAINER (window), button_box);
      grid = gtk_grid_new();
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    gtk_container_add(GTK_CONTAINER(window), grid);
    curl();
button = gtk_label_new(price);
update = gtk_button_new_with_label("Update");
  g_signal_connect (update, "clicked", G_CALLBACK (print_hello), NULL);
  //g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
 // gtk_container_add (GTK_CONTAINER (button_box), button);
gtk_grid_attach(GTK_GRID(grid), button, 3, 1, 4, 2);
gtk_grid_attach(GTK_GRID(grid), update, 3, 3, 4, 3);
 picardia = gtk_image_new_from_file("picardia.png");
 gtk_grid_attach(GTK_GRID(grid), picardia, 1, 1, 2, 3);
  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}


