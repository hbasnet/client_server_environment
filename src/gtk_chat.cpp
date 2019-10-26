#include <iostream>
#include <gtk/gtk.h>

static void destroy_event(GtkWidget *widget, gpointer data)
{
   gtk_main_quit();
}

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
   return FALSE; // must return false to trigger destroy event for window
}

void clearCallback(GtkWidget *widget, GdkEventButton *event, gpointer callback_data)
{
   std::cerr << "clear button pressed: " << event->button << std::endl;
}

void sendCallback(GtkWidget *widget, GdkEventButton *event, gpointer callback_data)
{
   std::cerr << "send button pressed: " << event->button << std::endl;
}

int main(int argc, char *argv[])
{

   gtk_init( &argc, &argv);

   GtkWidget *window = NULL;

   GtkWidget *clearButton,*sendButton = NULL;
   GtkWidget *toView  = NULL;  // text to the chat server
   GtkWidget *fromView  = NULL;  // text from the chat server

   GtkTextBuffer *toBuffer = NULL;


   toView = gtk_text_view_new ();
   fromView = gtk_label_new (NULL);


   toBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (toView));


   gtk_text_buffer_set_text (toBuffer, "First message to be sent", -1);
   gtk_label_set_text (GTK_LABEL(fromView), "waiting for server");


   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   clearButton = gtk_button_new_with_label("Clear");
   sendButton = gtk_button_new_with_label("Send");


   GtkWidget *  vbox = gtk_vbox_new (false, 10);
   gtk_container_add(GTK_CONTAINER(window), vbox);


   gtk_box_pack_start(GTK_BOX(vbox),clearButton, TRUE,TRUE,0);
   gtk_box_pack_start(GTK_BOX(vbox),sendButton, TRUE,TRUE,0);
   gtk_box_pack_start(GTK_BOX(vbox),toView, TRUE,TRUE,0);
   gtk_box_pack_start(GTK_BOX(vbox),fromView, TRUE,TRUE,0);


   g_signal_connect(G_OBJECT(clearButton), "button_press_event", G_CALLBACK(clearCallback), NULL);
   g_signal_connect(G_OBJECT(sendButton), "button_press_event", G_CALLBACK(sendCallback), NULL);


   gtk_widget_show_all(window);
   g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);
   g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy_event), NULL);

   gtk_main();
   return 0;
}
