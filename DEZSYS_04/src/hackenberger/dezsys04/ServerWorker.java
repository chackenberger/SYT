package hackenberger.dezsys04;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

//DEZSYS-04 Hackenberger Christoph
public class ServerWorker extends Thread {

	private Socket clientSocket;
	
	public ServerWorker(Socket s) {
		this.clientSocket = s;
	}
	
	@Override
	public void run() {
		try(
			//Neuer PrintWriter wird erstellt der auf den OutputStream, des erstellten Sockets, schreibt 
			PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
        	//Neuer BufferedReader wird erstellt der vom InputStream, des erstellten Sockets, liest
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
		) {
		String inputLine, outputLine;
        
        // Initiate conversation with client
        KnockKnockProtocol kkp = new KnockKnockProtocol();
        outputLine = kkp.processInput(null);
        //Schreibt einen String auf den PrintWriter out dieser schreibt im Hintergrund auf den Outputstream
        // des Sockets und sendet den String somit an den Client
        out.println(outputLine);

        //Liest solange eine Zeile vom BufferReader in (dieser liest vom InputStream des Sockets) bis
        //das Ende des Streams erreicht wurde (was zum Bsp. der Fall ist wenn der Client die Verbindung
        //schließt)
        while ((inputLine = in.readLine()) != null) {
            outputLine = kkp.processInput(inputLine);
            //Schreibt einen String auf den PrintWriter out dieser schreibt im Hintergrund auf den Outputstream
            // des Sockets und sendet den String somit an den Client
            out.println(outputLine);
            if (outputLine.equals("Bye."))
                break;
        }
		}catch (IOException e) {
			System.out.println("Exception caught when trying to listen on port "
	                + clientSocket.getPort() + " or listening for a connection");
	            System.out.println(e.getMessage());
		}
	}
}
