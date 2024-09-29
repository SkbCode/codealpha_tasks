#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


string toLowerCase(const string &str) 
{
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}


string analyzeSentiment(const string &input) 
{

    string positiveWords[] = {"good", "happy", "great", "excellent", "love"};
    string negativeWords[] = {"bad", "sad", "angry", "terrible", "hate"};

    for (string word : positiveWords) 
	{
        if (input.find(word) != string::npos)
            return "positive";
    }
    
    for (string word : negativeWords) 
	{
        if (input.find(word) != string::npos)
            return "negative";
    }

    return "neutral";
}


string handleQuestions(const string &input) 
{
    map<string, string> predefinedAnswers = 
	{
        {"what is your name", "I am an AI chatbot."},
        {"how are you", "I am just a bunch of code, but thanks for asking!"},
        {"what is ai", "AI stands for Artificial Intelligence."},
        {"who created you", "I was created by a C++ programmer."}
    };

    string lowerInput = toLowerCase(input);

    for (const auto &pair : predefinedAnswers) 
	{
        if (lowerInput.find(pair.first) != string::npos) 
		{
            return pair.second;
        }
    }

    return "Sorry, I don't know the answer to that.";
}


void chatbot() 
{
    string input;
    cout << "Welcome to the AI chatbot. Type 'exit' to end the conversation.\n";

    while (true) 
	{
        cout << "You: ";
        getline(cin, input);

        if (toLowerCase(input) == "exit") 
		{
            cout << "Goodbye!\n";
            break;
        }

     
        string sentiment = analyzeSentiment(input);
        cout << "[Sentiment Analysis]: The sentiment seems to be " << sentiment << ".\n";

      
        string response = handleQuestions(input);
        cout << "Bot: " << response << endl;
    }
}

int main() 
{
    chatbot();
    return 0;
}

