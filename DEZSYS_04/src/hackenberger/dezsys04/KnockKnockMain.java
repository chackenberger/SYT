package hackenberger.dezsys04;

import java.io.IOException;

//DEZSYS-04 Hackenberger Christoph
public class KnockKnockMain {

	public static void main(String[] args) throws InterruptedException, IOException {
		
		 if (args.length != 2) {
	            System.err.println("Usage: java -jar knockknock.jar <host> <port number>");
	            System.exit(1);
	     }
		 
		 String host = args[0];
		 int port = Integer.parseInt(args[1]);
		 
		 new KnockKnockServer(port).start();
		 
		 System.out.println("Waiting for the server to start...");
		 Thread.sleep(1500);
		 new KnockKnockClient().talkToServer(host, port);
	}
}
