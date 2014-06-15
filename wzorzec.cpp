// wzorzec.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace wzorzec;

using namespace System;
using namespace System::IO;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;
using namespace System::Threading;

static void connection()
{	
	
try
   {
      // Set the TcpListener on port 13000.
      Int32 port = 13000;
      IPAddress^ localAddr = IPAddress::Parse( "127.0.0.1" );

      // TcpListener* server = new TcpListener(port);
      TcpListener^ server = gcnew TcpListener( localAddr,port );

      // Start listening for client requests.
      server->Start();

      // Buffer for reading data 
      array<Byte>^bytes = gcnew array<Byte>(256);

      // Enter the listening loop. 
      while ( true )
      {
         Console::Write( "Waiting for a connection... " );

         // Perform a blocking call to accept requests. 
         // You could also user server.AcceptSocket() here.
         TcpClient^ client = server->AcceptTcpClient();
         Console::WriteLine( "Connected!" );
		 MessageBox::Show( "Connected!");

         // Get a stream Object* for reading and writing
         NetworkStream^ stream = client->GetStream();
         Int32 i;

//////////////////////////
	 String^ message=Form1::richText;

	  ASCIIEncoding^ ascii = gcnew ASCIIEncoding;
	  array<Byte>^data =ascii->GetBytes(message);

	  stream->Write( data, 0, data->Length );
	  	
	//////////////////////////

         // Loop to receive all the data sent by the client. 
         while ( i = stream->Read( bytes, 0, bytes->Length ) )
         {
            // Translate data bytes to a ASCII String*.
			ASCIIEncoding^ ascii = gcnew ASCIIEncoding;
			String^ data = ascii->GetString( bytes );
            Console::WriteLine( "Received: {0}", data );

            // Process the data sent by the client.
            data = data->ToUpper();
			ASCIIEncoding^ ascii2 = gcnew ASCIIEncoding;
            array<Byte>^msg = ascii2->GetBytes( data );

            // Send back a response.
            stream->Write( msg, 0, msg->Length );
            Console::WriteLine( "Sent: {0}", data );
         }
         client->Close();
		 server->Stop();

   }
}
   catch ( SocketException^ e ) 
   {
      Console::WriteLine( "SocketException: {0}", e );
   }
   
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	ThreadStart^ threadDelegate = gcnew ThreadStart(connection);
	Thread^ newThread1 = gcnew Thread( threadDelegate );
	newThread1->Start();

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
}


 