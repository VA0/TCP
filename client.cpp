#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstring>
#include <SFML/Network.hpp>

using std::cout, std::endl;

//TCP Server
int main()
{

    // klient
    sf::TcpSocket socket; // tworzymy gniazdo klienta
    sf::IpAddress ip = "127.0.0.1";
    unsigned int port = 7000;

    if (socket.connect( ip, port ) != sf::Socket::Done) // łączymy się z adresem 'ip' na porcie 'port'
    // jeśli funkcja connect zwróci sf::Socket::Done oznacza to, że wszystko poszło dobrze
    {
        cout << "I cant connect with " << ip.toString() << " on port " << port << endl;
        exit( 1 );
    }


    const int datasize = 1000;
    char data[ datasize ] = "test";

    //Sending datetime 5 times to the server
    for (int i=0; i < 5; i++)
    {

        time_t time = std::time(0);
        tm time2;
        localtime_s(&time2, &time);
        strftime(data, datasize, "%Y-%m-%d %H:%M:%S", &time2);


        //sending data (size is actual str + null terminating character)
        if( socket.send( data, strlen(data)+1 ) != sf::Socket::Done )
        {
            cout << "I cant send the data!\n";
            exit( 1 );
        }

        //receiving data
        // std::size_t received; //bytes read
        // if( socket.receive( data, datasize, received ) != sf::Socket::Done )
        // {
        //     cout << "I cant receive the data from the server!\n";
        //     exit( 1 );
        // }
        // else
                //cout << "Server: " << data << " |" << received << " bytes|" << endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  

    socket.disconnect();

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
