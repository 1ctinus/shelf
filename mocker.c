#include <gtk/gtk.h>
#include <gdk/gdk.h>
GtkWidget *textbox;
static GtkWidget *result;
static void
clippy (GtkWidget *widget)
{


  // Initialize a GValue with the contents of the widget
  GValue value = G_VALUE_INIT;
  g_value_init (&value, G_TYPE_STRING);
  g_value_set_string (&value, gtk_label_get_text (GTK_LABEL(result)));

  // Store the value in the clipboard object
  GdkClipboard *clipboard = gtk_widget_get_clipboard (result);
  gdk_clipboard_set_value (clipboard, &value);

  g_value_unset (&value);
}

void mock(GtkWidget *calculate, gpointer data){
    GtkTextIter start, end;
    GtkTextBuffer *bufferz = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textbox));
    char *mocked;

    gtk_text_buffer_get_bounds(bufferz, &start, &end);
    mocked = gtk_text_buffer_get_text(bufferz, &start, &end, FALSE);
    gtk_text_buffer_delete(bufferz, &start, &end);

    for (int i = 0; mocked[i] != '\0'; i = i + 2){
        if (mocked[i] >= 'a' && mocked[i] <= 'z' && mocked[(i - 1)] != '\\'){
            mocked[i] = mocked[i] - 32;
        }
    }


    gtk_label_set_text(GTK_LABEL(result), mocked);
}
static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Mocker");
  gtk_window_set_default_size (GTK_WINDOW (window), 240, 520);
  gtk_window_set_default_icon_name ("gtk3-demo");

  
    grid = gtk_grid_new();
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
  //  gtk_container_add(GTK_CONTAINER(window), grid);
gtk_window_set_child (GTK_WINDOW (window), grid);
   textbox = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textbox), GTK_WRAP_WORD);
    gtk_text_view_set_left_margin(GTK_TEXT_VIEW(textbox), 15);
 gtk_text_view_set_top_margin(GTK_TEXT_VIEW(textbox), 5);
    GtkWidget *scrolled_window = gtk_scrolled_window_new();
    gtk_widget_set_size_request(scrolled_window, 200, 200);

   gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window),
		   textbox);
    gtk_grid_attach(GTK_GRID(grid), scrolled_window, 1, 1, 2, 1);
    GtkWidget *calculate = gtk_button_new_with_label("Mockify");
    GtkWidget *clip = gtk_button_new_with_label("Copy");

    g_signal_connect(clip, "clicked", G_CALLBACK(clippy), NULL);
    
    g_signal_connect(calculate, "clicked", G_CALLBACK(mock), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), clip, 2, 2, 2, 1);
        result = gtk_label_new("results will be shown here");
    gtk_label_set_selectable(GTK_LABEL(result), TRUE);
gtk_label_set_wrap (GTK_LABEL(result), TRUE);
    gtk_label_set_max_width_chars(GTK_LABEL(result), 30);
    GtkWidget *label_scroll = gtk_scrolled_window_new();
    gtk_widget_set_size_request(label_scroll, 200, 200);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(label_scroll),
                      result);
     gtk_grid_attach(GTK_GRID(grid), label_scroll, 1, 3, 2, 1);
  gtk_widget_show (window);
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
