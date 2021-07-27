#include <iostream>
#include <SFML/Network.hpp>

using std::cout, std::endl;

//TCP Server
int main()
{

    sf::TcpListener listener; //creating listener socket
    unsigned int port = 7000;

    if( listener.listen( port ) != sf::Socket::Done ) //start listenning on port 7000
    {
        cout << "I cant start listening on port " << port << endl;
        exit( 1 );
    }
    else
    {
        cout << "Listening on port " << port << endl;
    }


    const int datasize = 1000;
    char data[ datasize ] = "test";

    sf::TcpSocket client; //creating socket to communicate with a client

    while( 1 )
    {

           
        listener.accept( client );
        listener.setBlocking(false); 
       
        //auto pub_ip = sf::IpAddress::getPublicAddress();
        

        ////sending data
        // if( client.send( data, datasize ) != sf::Socket::Done ) // i wysyłamy...
        // {
        //     cout << "I cant send the data to the client!\n";
        //     exit( 1 );
        // }


        //Socket::Status TcpSocket::receive(void* data, std::size_t size, std::size_t& received)
        //receiving data
        std::size_t received; //bytes read
        if( client.receive( data, datasize, received ) != sf::Socket::Done ) // i wysyłamy...
        {
            cout << "I cant receive the data from the client!\n";
            cout << "Disconnecting the client!\n";
            listener.setBlocking(true); 
            client.disconnect();

            //break;
        }
        else
            cout << client.getRemoteAddress() << ":" << client.getRemotePort() << " > " << data << " |" << received << " bytes|" << endl;



        
    }
    listener.close();


    return 0;

}


// #include <SFML/Graphics.hpp>

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//     sf::CircleShape shape(100.f);
//     shape.setFillColor(sf::Color::Green);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         window.clear();
//         window.draw(shape);
//         window.display();
//     }

//     return 0;
// }
