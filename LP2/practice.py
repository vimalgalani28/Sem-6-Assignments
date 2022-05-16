import nltk
from nltk.chat.util import Chat, reflections

reflections = {
    "i am"       : "you are",
    "i was"      : "you were",
    "i"          : "you",
    "i'm"        : "you are",
    "i'd"        : "you would",
    "i've"       : "you have",
    "i'll"       : "you will",
    "my"         : "your",
    "you are"    : "I am",
    "you were"   : "I was",
    "you've"     : "I have",
    "you'll"     : "I will",
    "your"       : "my",
    "yours"      : "mine",
    "you"        : "me",
    "me"         : "you",
    "do you"     : "is there any",
}

pairs = [
    [
        r"My name is (.*)",
        ["Hello %1, How may I help you?"]
    ],
        [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ], 
    [
        r"what is your name ?",
        ["I am a bot created by PICT gym. you can call me Hitlar!",]
    ],
    [
        r"how are you ?",
        ["I'm doing good. How about You ?",]
    ],
    [
        r"sorry (.*)",
        ["Its alright","Its OK, never mind",]
    ],
    [
        r"I am fine",
        ["Great to hear that, How can I help you?",]
    ],
    [
        r"i'm (.*) doing good",
        ["Nice to hear that","How can I help you?:)",]
    ],
    [
        r"(.*) age?",
        ["I'm a computer program dude. Seriously you are asking me this?",]
    ],

    [
        r"(.*) time | timing | available",
        ["Our gym is open from 5:00AM to 11:00AM and 5:00pm to 11:00pm."]
    ],
    [
        r"(.*) is your monthly fees",
        ["We provide monthy subcription for 800₹ and for a year 8000₹."]
    ],
    [
        r"(.*) is (.*) monthly rate",
        ["We provide monthy subcription for 800₹ and for a year 8000₹."]
    ],
    [
        r"(.*) trainer available",
        ["We have 4 trainers available to train your body in a best way."]
    ],
    [ 
        r"(.*) sports facility available",
        ["We have boxing facility available."]
    ]
]

def chat() :
    print("Hello this is PICT GYM. What is your name?")
    chat = Chat(pairs, reflections)
    chat.converse()

chat()
