// StlListExample.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <list>

class Message
{
private:
	const unsigned int payload_size;
	const unsigned int frame_length;
public:
	Message(): payload_size(0), frame_length(0) {}
	Message(unsigned int payload_size,
		unsigned int frame_length) :
		payload_size(payload_size),
		frame_length(frame_length) {}

	int messageSize() const
	{
		return payload_size * frame_length;
	}
};



int main()
{
	std::list<Message> messages;
	messages.push_front(Message(500, 80));
	messages.push_front(Message(400, 80));
	messages.push_front(Message(700, 80));
	messages.push_front(Message(800, 80));

	for (const auto &v : messages)
	{
		std::cout << v.messageSize() << std::endl;
	}

	

    return 0;
}

