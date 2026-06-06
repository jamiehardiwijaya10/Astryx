#include <iostream>
#include <windows.h>
#include "../miniGames/memoryCard.cpp"
#include "branch.cpp"
using namespace std;


int chap1a(string username){
    system("cls");
    typing("CHAPTER 1 - RETURN TO MORIVELLE", 50);
    Sleep(800);
    
    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("ACT 1 - The Night Raiders", 50);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ariolla Monument, Ariolla Port, Morivelle City.", 50);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("23 September 1891", 30);
    Sleep(500);
    typing("10.51 PM", 30);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("After traveling for 14 hours from Elpis Harbor, Elias arrives in Morivelle.\n", 30);
    Sleep(500);
    typing("Specifically at Ariolla Port, which was once the center of tourist arrivals to Morivelle and 1 of the 5 major regions in Morivelle\n", 30);
    Sleep(500);
    
    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "Is this... A-Ariolla Port?", 30);
    Sleep(500);
    dialog("Elias", "W-What happened here?", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ariolla Port, which was once thriving with tourists, has become a desolate dead city. Buildings that were once magnificent are now destroyed and filled with wild plants.\n", 30);
    Sleep(500);
    typing("The harbor, which was once full of ships, is now empty and filled with scattered garbage.\n", 30);
    Sleep(500);
    typing("Elias walks through the harbor with mixed emotions of sadness, anger, and confusion.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "The Crimson Genesis phenomenon hasn't been able to cause such massive destruction.", 30);
    Sleep(500);
    dialog("Elias", "Is this the peak of destruction from The Crimson Genesis?", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Putting aside her emotions, Elias goes to find out what happened to her hometown\n", 30);
    Sleep(500);
    typing("She begins searching for information by examining the buildings that still stand, looking for clues about what happened at Ariolla Monument.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias finds a locked box.", 30);
    Sleep(500);
    typing("Elias tries to open the box\n", 30);
    Sleep(500);

    typing("Notice: You will enter a mini-game to open the box. If you win, you can continue the story. Try your best to win this mini-game!", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");    

    saveGame(username,1,2);
    return 0;
}

int chap1b(string username){
    system("cls");
    typing("The box opens!", 30);
    Sleep(500);
    typing("The box is empty. Elias feels disappointed.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias tries to continue his investigation deeper into the main Ariolla monument.\n", 30);
    Sleep(500);
    typing("This monument stands majestically in the Ariolla Monument area, with a large statue depicting a woman holding a crystal ball.\n", 30);
    Sleep(500);
    typing("The statue looks very old and is already beginning to deteriorate, with many parts missing or broken.\n", 30);
    Sleep(500);
    typing("This monument was named Ariolla after a female hero who once saved Morivelle from pirate attacks in the 17th century.\n", 30);
    Sleep(500);
    typing("Elias examines the statue carefully, trying to find clues about what happened at Ariolla.\n", 30);
    Sleep(500);

    typing("Notice: You will enter a mini-game to examine clues on the statue. If you win, you can continue the story. Try your best to win this mini-game!", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");    

    saveGame(username,1,4);
    return 0;
}

int chap1c(string username){
    system("cls");
    typing("The statue is successfully analyzed!\n", 30);
    Sleep(500);
    typing("From the analysis results, Elias discovers that the damage that occurred at Ariolla Port seems to come from one direction.\n", 30);
    Sleep(500);
    typing("This damage appears to come from the northwest direction, which means in all likelihood the damage comes from the direction of Morivelle City center.\n", 30);
    Sleep(500);
    typing("Elias decides to go northwest.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Rovenila, Ariolla Port, Morivelle City.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias arrives at Rovenila, an area that was once the center of government for the Ariolla Port region\n", 30);
    Sleep(500);
    typing("This area was once filled with magnificent government buildings, but now has turned into desolate ruins filled with wild plants.\n", 30);
    Sleep(500);
    typing("Elias begins exploring this area, looking for clues about what happened at Ariolla.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("As Elias walks through the streets of Rovenila, a creature appears from behind the ruins. This creature looks like a human, but with red skin and glowing eyes.\n", 30);
    Sleep(500);
    typing("The creature approaches Elias with slow but steady steps, like a normal human walking, but the aura emanating from this creature is very frightening and intimidating.\n", 30);
    Sleep(500);
    typing("Driven by curiosity and great intrigue, Elias decides to approach the creature, hoping to get clues about what happened at Ariolla.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias approaches the creature carefully, trying not to arouse suspicion or threat to the creature.\n", 30);
    Sleep(500);
    typing("However, as Elias gets closer, the creature also approaches Elias with stumbling steps, as if the creature is also curious about Elias.\n", 30);
    Sleep(500);
    typing("When the two are close enough, the creature suddenly attacks Elias\n", 30);
    Sleep(500);
    typing("Armed with a handgun and quick reflexes, Elias successfully dodges the attack and retaliates by shooting the creature several times.\n", 30);
    Sleep(500);
    typing("However, the sound of gunfire echoes throughout Rovenila, drawing the attention of similar creatures hidden behind the ruins.\n", 30);
    Sleep(500);
    typing("Notice: You will enter a battle to fight the creature. If you win, you can continue the story. Try your best to win this battle!", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,6);
    return 0;

}

int chap1d(string username){
    system("cls");
    typing("Elias successfully defeats the creature!\n", 30);
    Sleep(500);
    typing("After defeating the creature, Elias glances at the creature's body to look for clues about what happened at Ariolla.\n", 30);
    Sleep(500);
    typing("However, as more similar creatures appear, Elias decides to quickly leave Rovenila and return to Ariolla Monument.\n", 30);
    Sleep(500);
    typing("She plans to return first to Demirgus and make preparations for a major investigation at Ariolla.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Without clarity, Ariolla Monument becomes filled with similar creatures. There is also a very large creature.\n", 30);
    Sleep(500);
    typing("This large creature has dark red skin, like a human with its skin ripped off. Its mouth is wide with sharp teeth and a long tongue\n", 30);
    Sleep(500);
    typing("Seeing no way out, Elias decides to go south, trying to reach the other side of the beach to find a way out of Ariolla.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias successfully enters the forest on the south side of Rovenila. After running for a while, he can catch his breath and tries to find a way out of the forest.\n", 30);
    Sleep(500);
    typing("Elias finds a small hut that looks like a dwelling. The hut looks like a guard post and its condition is still well maintained, unlike the surrounding area which is already destroyed.\n", 30);
    Sleep(500);
    typing("Elias decides to approach the hut, hoping to find clues about what happened at Ariolla.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("As Elias approaches the hut, he sees a man and a woman talking inside. They look like normal humans, but the aura they emanate is very different from the similar creatures in Rovenila.\n", 30);
    Sleep(500);
    typing("Elias decides to approach them carefully, trying not to arouse suspicion or threat to them.\n", 30);
    Sleep(500);
    typing("Elias approaches them and tries to start a conversation. However, the man suddenly points a knife at Elias.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Stoic Man", "Who are you!?", 30);
    Sleep(500);
    dialog("Elias", "I... I'm here to go home to Morivelle...", 30);
    Sleep(500);
    dialog("Elias", "I'm from Morivelle...", 30);
    Sleep(500);
    dialog("Elias", "and I came from Demirgus.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("The man looks hesitant, but the woman next to him approaches Elias.\n", 30);
    Sleep(500);
    typing("She forcibly examines Elias's hand, trying to find clues about who Elias really is.\n", 30);
    Sleep(500);
    typing("After a while, the woman seems satisfied with what she finds on Elias's hand.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Cheerful Woman", "At least you're not part of them...", 30);
    Sleep(500);
    dialog("Cheerful Woman", "But your identity... You should come with us...", 30);
    Sleep(500);
    dialog("Stoic Man", "What are you doing Ririsa?", 30);
    Sleep(500);
    dialog("Ririsa", "You said you came from Demirgus, didn't you?", 30);
    Sleep(500);
    dialog("Ririsa", "You also said you're here to go home to Morivelle, didn't you?", 30);
    Sleep(500);
    dialog("Ririsa", "Simple, the conclusion is she's a native Morivelle citizen who went to Demirgus to work, but now she's coming back to Morivelle...", 30);
    Sleep(500);
    dialog("Elias", "Actually, to study.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "You see...", 30);
    Sleep(500);
    typing("\nThe man slowly lowers his knife.\n", 30);
    Sleep(500);
    dialog("Stoic Man", "Okay.", 30);
    Sleep(500);
    typing("\nThe man says with a still hesitant voice, but he seems more calm than before.\n", 30);
    Sleep(500);
    dialog("Ririsa", "Sorry hehe... My husband is a bit paranoid about security, especially with the current situation.", 30);
    Sleep(500);
    dialog("Ririsa", "My name is Ririsa, this is my husband, Darius.", 30);
    Sleep(500);
    dialog("Ririsa", "You can come with us. For the safety of our village and also to possibly answer your confusion.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ririsa and Elias go to the village in the forest, leaving Darius at the guard post.", 30);
    Sleep(500);
    typing("While walking towards the village, Elias asks Ririsa.\n");
    Sleep(500);
    dialog("Elias", "How are you...", 30);
    Sleep(500);
    dialog("Ririsa", "From your situation and your explanation, it's clear what your condition is now. You're confused about what's happening here.", 30);
    Sleep(500);
    dialog("Elias", "You come from a village? I don't remember a village in this area.", 30);
    Sleep(500);
    dialog("Elias", "How long ago did you leave Morivelle?", 30);
    Sleep(500);
    dialog("Elias", "Almost 5 years ago", 30);
    Sleep(500);
    dialog("Ririsa", "Hmm... No wonder. We didn't exist 5 years ago.", 30);
    Sleep(500);
    dialog("Elias", "So you...?");
    Sleep(500);
    dialog("Ririsa", "Yup. You guessed it. We're not from Morivelle. We're immigrants from far away.", 30);
    Sleep(500);
    dialog("Elias", "You're so cheerful and not reluctant to give information like this.", 30);
    Sleep(500);
    dialog("Ririsa", "Why would that be? I like talking to someone my age. It's rare that I have a female friend my age.", 30);
    Sleep(500);
    dialog("Elias", "Oh...\n", 30);
    Sleep(500);
    typing("Soon after, they arrive at the village.");
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Village of Purification, Ariolla Port, Morivelle City.", 50);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "Welcome to the village of The Night Raiders or as outsiders call it, the Village of Purification", 30);
    Sleep(500);
    dialog("Elias", "The Night Raiders? Village of Purification?", 30);
    Sleep(500);
    dialog("Ririsa", "Ah... The Night Raiders is the name for our people.", 30);
    Sleep(500);
    dialog("Ririsa", "We are a nomadic people. We lived island to island. Now we live here. But because of some situations and current conditions, it seems we will continue to live here.", 30);
    Sleep(500);
    typing("Hesitant to ask, Elias just falls silent and doesn't dare continue the conversation\n", 30);
    Sleep(500);
    dialog("Ririsa", "Well... That's not too important. As for this village itself, it's named Village of Purification because this area was very contaminated in the past.", 30);
    Sleep(500);
    dialog("Ririsa", "The Night Raiders have a special ability in purification or cleansing. We can clean contaminated water, soil, and air with our abilities.", 30);
    Sleep(500);
    dialog("Ririsa", "Not only that, we can also clean living creatures that are contaminated with our abilities.", 30);
    Sleep(500);
    dialog("Elias", "Living creatures that are contaminated?", 30);
    Sleep(500);
    dialog("Ririsa", "Yes, living creatures that are contaminated with black spots that we're trying to figure out. We can clean them with our abilities.", 30);
    Sleep(500);
    dialog("Elias", "Black spots?", 30);
    Sleep(500);
    dialog("Ririsa", "Yes, black spots are like stains that appear on the skin of living creatures. We don't know what causes it yet, but we suspect it's some kind of infection or disease caused by some phenomenon.", 30);
    Sleep(500);
    dialog("Elias", "Phenomenon? Do you mean The Crimson Genesis?", 30);
    Sleep(500);
    dialog("Ririsa", "The Crimson Genesis? What is that?", 30);
    Sleep(500);
    dialog("Elias", "Emm... It's just my theory, I can explain it later at the right time.", 30);
    Sleep(500);
    dialog("Ririsa", "Okay then, we can talk about that later. Anyway, that's why this village is named Village of Purification.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ririsa then takes Elias to the home of the leader of The Night Raiders.\n", 30);
    Sleep(500);
    dialog("Ririsa", "Gary, I brought a new friend. She says she's from Morivelle.", 30);
    Sleep(500);
    typing("\nA middle-aged man with long hair tied back appears from inside the house and greets Elias warmly.\n", 30);
    Sleep(500);
    dialog("Gary", "From Morivelle? Is there a survivor?", 30);
    Sleep(500);
    dialog("Ririsa", "No. She comes from outside the city. She's here to go home.", 30);
    Sleep(500);
    dialog("Gary", "So, a native Morivelle citizen who went outside the city and came home without knowing the state of the city. You must have lived alone and far from Morivelle for a very long time.", 30);
    Sleep(500);
    dialog("Elias", "Emm... You could say that.", 30);
    Sleep(500);
    dialog("Gary", "Ririsa, can you wait outside and give me time to talk with this Morivelle lady", 30);
    Sleep(500);
    dialog("Ririsa", "Of course Gary. I'll wait outside\n", 30);
    Sleep(500);
    typing("Ririsa steps out with a bright smile.", 30);
    Sleep(500);
    typing("Gary then invites Elias into his house to talk further", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Gary", "May I know more about you?", 30);
    Sleep(500);
    dialog("Elias", "Emm... My name is Elias Viremont. I was born in Morivelle and I grew up here until I was 18.", 30);
    Sleep(500);
    dialog("Elias", "At that time I got a scholarship to study at Demirgus University.", 30);
    Sleep(500);
    dialog("Elias", "I left Morivelle for education exactly 5 years ago and everything was normal back then.", 30);
    Sleep(500);
    dialog("Gary", "I understand, but do you know what happened here?", 30);
    Sleep(500);
    dialog("Elias", "No. Do you know what happened here?", 30);
    Sleep(500);
    dialog("Gary", "No.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Gary", "We came exactly 2 years ago when everything here was already destroyed", 30);
    Sleep(500);
    dialog("Gary", "We are nomadic. When we came to this area, everything seemed to be possessed by Yokai", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Gary", "We managed to purify this area with our special abilities", 30);
    Sleep(500);
    dialog("Gary", "We also built our settlement here, which later became our place of residence", 30);
    Sleep(500);
    dialog("Gary", "The area here is not as contaminated as other places.", 30);
    Sleep(500);
    dialog("Gary", "What still confuses us is why this city became so destroyed and contaminated.", 30);
    Sleep(500);
    dialog("Gary", "We searched to see if anyone was rescued or also living here", 30);
    Sleep(500);
    dialog("Gary", "We also studied the natural situation around here", 30);
    Sleep(500);
    dialog("Gary", "Both ended in nothing and there's nothing that can be explained according to our knowledge", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "In Demirgus, I'm also experimenting with something similar,", 30);
    Sleep(500);
    dialog("Elias", "In Demirgus something that changes natural phenomena is also happening, only not as severe as here.", 30);
    Sleep(500);
    dialog("Elias", "In theory, this is called The Crimson Genesis. A phenomenon where nature changes itself into something more dangerous and destructive.", 30);
    Sleep(500);
    dialog("Elias", "The Crimson Genesis can change everything in nature, including living creatures, into something more dangerous and destructive.", 30);
    Sleep(500);
    dialog("Elias", "This phenomenon can happen suddenly and spread quickly.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Gary", "So do you mean nature has a will of its own? That sounds strange,", 30);
    Sleep(500);
    dialog("Elias", "This is still just my theory, and because it sounds strange, that's why I'm investigating this Crimson Genesis more deeply,", 30);
    Sleep(500);
    dialog("Gary", "So you're actually here to investigate this?", 30);
    Sleep(500);
    dialog("Elias", "Not exactly. My professor asked me to take a vacation so I decided to go home,", 30);
    Sleep(500);
    dialog("Gary", "Hmm. Now the question for me is what are you going to do next?", 30);
    Sleep(500);
    dialog("Elias", "I originally wanted to go back to Demirgus and ask for help to conduct an investigation to Morivelle,", 30);
    Sleep(500);
    dialog("Elias", "However, because the harbor has started to be blocked by those strange creatures, I can't go back.", 30);
    Sleep(500);
    dialog("Gary", "Since we're both in a confusing situation, I will help you with your research.", 30);
    Sleep(500);
    dialog("Gary", "If you really want to go back and investigate this all until the truth is revealed, I will be happy to help.", 30);
    Sleep(500);
    dialog("Elias", "How are you going to help me?", 30);
    Sleep(500);
    dialog("Gary", "We can help you clean the harbor area and rebuild it so you can go back,", 30);
    Sleep(500);
    dialog("Elias", "Do you mean the Ariolla Monument area?", 30);
    Sleep(500);
    dialog("Gary", "Yes, whatever that place is called. We need to clean that area and rebuild it so that when you come back here later, you can arrive safely.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Gary", "So... do we have a deal?", 30);
    Sleep(500);
    dialog("Elias", "Alright, I promise you that what happened here I will solve,", 30);
    Sleep(500);
    typing("Gary smiles", 30);
    Sleep(500);
    dialog("Gary", "Okay, we have a deal. I will inform Ririsa and Darius to accompany you. Maybe you can tell Ririsa directly,", 30);
    Sleep(500);
    typing("Elias smiles, then she leaves Gary's house.\n", 30);
    Sleep(500);
    typing("Outside, Ririsa is already waiting cheerfully\n", 30);
    Sleep(500);
    dialog("Ririsa", "How was your conversation with Gary?", 30);
    Sleep(500);
    typing("Elias then tells Ririsa about her conversation with Gary.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "Wow... So we're going to clean up Ariolla Monument?", 30);
    Sleep(500);
    dialog("Elias", "Yes, we will clean up Ariolla Monument so I can go back to Demirgus,", 30);
    Sleep(500);
    dialog("Ririsa", "Cool! When do we start?", 30);
    Sleep(500);
    typing("Tutorial: You will begin city building to clean and rebuild Ariolla Monument. If you successfully rebuild Ariolla Monument, you can continue the story. Try your best to rebuild Ariolla Monument!", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,8);
    return 0;
}

int chap1e(string username){
    system("cls");

    typing("ACT 2 - The Old Hunted City", 50);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("After days of preparation, Ariolla Monument has finally been cleared of most of the Crimson-infected structures.\n", 30);
    Sleep(500);
    typing("The air feels lighter, but the silence is still unnatural... as if the land is waiting for something.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("As Elias prepares to leave Ariolla, Ririsa and Darius accompany her for one last sweep of the area.\n", 30);
    Sleep(500);
    typing("However, something changes. The ground begins to tremble softly.\n", 30);
    Sleep(500);
    typing("Crimson veins beneath the soil start to pulse again.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("From the collapsed ruins, corrupted creatures begin emerging once more.\n", 30);
    Sleep(500);
    typing("Not just small ones... but a massive one, far larger than anything they had faced before.\n", 30);
    Sleep(500);
    typing("Its body looks like a fusion of flesh, roots, and broken stone, as if the land itself refused to stay purified.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "So it wasn't fully gone...", 30);
    Sleep(500);
    dialog("Darius", "Stay behind Elias. This one is different.", 30);
    Sleep(500);
    dialog("Elias", "No... I'll fight too. This is my responsibility.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("The battle begins.\n", 30);
    Sleep(500);
    battle2(username);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("The creature roars, splitting into smaller corrupted fragments.\n", 30);
    Sleep(500);
    typing("But Ririsa reacts quickly, expanding her purification field and stabilizing the environment.\n", 30);
    Sleep(500);
    typing("Darius finishes the core with a final strike.\n", 30);
    Sleep(500);
    typing("The monster collapses, dissolving into ash-like crimson particles.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Silence returns.\n", 30);
    Sleep(500);
    typing("This time... it feels real.\n", 30);
    Sleep(500);
    typing("Ariolla Monument is finally still.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "Looks like we actually did it this time.", 30);
    Sleep(500);
    dialog("Darius", "Don't celebrate yet. This place is still unstable.", 30);
    Sleep(500);
    dialog("Elias", "I need to go back to Demirgus now. I have to understand all of this.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias departs from Ariolla Monument alone, heading back toward Demirgus.\n", 30);
    Sleep(500);
    typing("The road feels familiar, but something about it feels... distorted.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("That night, Elias falls asleep near a checkpoint between regions.\n", 30);
    Sleep(500);
    typing("And then, the dream begins.\n", 30);
    Sleep(500);

    system("cls");

    typing("--- DREAM ---\n", 30);
    Sleep(500);
    typing("A younger Elias... age 18.\n", 30);
    Sleep(500);
    typing("Standing at Morivelle's gate, confused and nervous.\n", 30);
    Sleep(500);

    dialog("Professor Lucia", "Are you ready to leave Morivelle?", 30);
    Sleep(500);
    dialog("Elias (18)", "I... I think so.", 30);
    Sleep(500);
    dialog("Professor Lucia", "Demirgus is not just a university. It will change how you see the world.", 30);
    Sleep(500);
    dialog("Elias (18)", "Will I still be able to come back?", 30);
    Sleep(500);
    dialog("Professor Lucia", "Of course you will. Just make sure you survive what you learn there.", 30);
    Sleep(500);

    system("cls");

    typing("The dream shifts.\n", 30);
    Sleep(500);
    typing("The gate disappears.\n", 30);
    Sleep(500);
    typing("Professor Lucia's face becomes unclear... distorted by crimson static.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Elias wakes up.\n", 30);
    Sleep(500);
    typing("Demirgus is finally in sight.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("However...\n", 30);
    Sleep(500);
    typing("Something is wrong.\n", 30);
    Sleep(500);
    typing("No signs of Professor Lucia.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "Professor Lucia...?", 30);
    Sleep(500);
    dialog("Elias", "Where did she go...?", 30);
    Sleep(500);

    typing("Elias searches the university.\n", 30);
    Sleep(500);
    typing("Labs are abandoned. Notes are scattered. Research on The Crimson Genesis is partially erased.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "There's nobody here...", 30);
    Sleep(500);
    dialog("Elias", "I better get going.", 30);
    Sleep(500);

    typing("Outside the window, distant silhouettes move between buildings.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "If I ask for help... they'll be dragged into this too.", 30);
    Sleep(500);
    dialog("Elias", "I can't let that happen.", 30);
    Sleep(500);

    typing("Elias slowly gathers equipment from the abandoned lab.\n", 30);
    Sleep(500);
    typing("Tools, research notes, and prototype devices related to Genesis anomalies.\n", 30);
    Sleep(500);
    typing("She makes a decision.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "I'll investigate this myself.", 30);
    Sleep(500);
    dialog("Elias", "If the Crimson Genesis is spreading... then I need to understand it before anyone else gets hurt.", 30);
    Sleep(500);

    typing("Demirgus is no longer just a place of study.\n", 30);
    Sleep(500);
    typing("It has become the next unknown zone of the Crimson Genesis.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias returns to Ariolla Monument, this time carrying several research tools from Demirgus Laboratory.\n", 30);
    Sleep(500);
    typing("The equipment is not military-grade... but enough for field investigation and anomaly detection.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("From a distance, Darius notices Elias approaching alone.\n", 30);
    Sleep(500);
    typing("His expression immediately hardens.\n", 30);
    Sleep(500);

    dialog("Darius", "You came back... alone?", 30);
    Sleep(500);
    dialog("Darius", "No reinforcements? No plan? Just you?", 30);
    Sleep(500);
    dialog("Elias", "I had to move fast. Waiting for approval would take too long.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Darius", "This isn't a small incident anymore, Elias.", 30);
    Sleep(500);
    dialog("Darius", "You're treating it like a personal project.", 30);
    Sleep(500);

    dialog("Ririsa", "Darius, calm down.", 30);
    Sleep(500);
    dialog("Ririsa", "She's still here. That means she's still fighting with us.", 30);
    Sleep(500);

    typing("Ririsa places her hand on Darius' shoulder, calming him down.\n", 30);
    Sleep(500);
    typing("Darius exhales slowly and steps back.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Without further delay, another wave of corrupted creatures emerges from the ruins.\n", 30);
    Sleep(500);
    typing("A second battle begins.\n", 30);
    Sleep(500);
    battle3(username);
    Sleep(500);

    typing("Ririsa expands her purification field, stabilizing the environment.\n", 30);
    Sleep(500);
    typing("Darius engages the front line, cutting through corrupted masses.\n", 30);
    Sleep(500);
    typing("Elias uses her newly brought tools to analyze weak points and expose the core structure of the creatures.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("After a brutal fight, the last creature collapses into crimson dust.\n", 30);
    Sleep(500);
    typing("Ariolla Monument is quiet again... but only temporarily.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "Now talk to us. Why did you come alone this time?", 30);
    Sleep(500);

    dialog("Elias", "Demirgus has no one officially handling this situation.", 30);
    Sleep(500);
    dialog("Elias", "And involving the government... would only make things worse.", 30);
    Sleep(500);

    dialog("Darius", "Worse how?", 30);
    Sleep(500);

    dialog("Elias", "Because they don't treat anomalies like a threat.", 30);
    Sleep(500);
    dialog("Elias", "They treat them like resources.", 30);
    Sleep(500);

    typing("Elias pauses, then continues.\n", 30);
    Sleep(500);

    dialog("Elias", "Any research related to abnormal natural phenomena gets redirected into classified programs.", 30);
    Sleep(500);
    dialog("Elias", "Funding increases. Military involvement increases.", 30);
    Sleep(500);
    dialog("Elias", "And after that... everything becomes controlled, sealed, or erased.", 30);
    Sleep(500);

    dialog("Elias", "If I report Crimson Genesis officially...", 30);
    Sleep(500);
    dialog("Elias", "It stops being an investigation and becomes a weapon project.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "So you're hiding it on purpose?", 30);
    Sleep(500);

    dialog("Elias", "I'm containing it for now.", 30);
    Sleep(500);
    dialog("Elias", "Even my friends... I can't involve them yet.", 30);
    Sleep(500);
    dialog("Elias", "What we saw here isn't something normal researchers have ever recorded before.", 30);
    Sleep(500);

    dialog("Elias", "If I tell them everything now...", 30);
    Sleep(500);
    dialog("Elias", "They won't investigate it.", 30);
    Sleep(500);
    dialog("Elias", "They'll panic.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "And Demirgus?", 30);
    Sleep(500);
    dialog("Elias", "Demirgus is safe. That's why I can still move freely.", 30);
    Sleep(500);
    dialog("Elias", "But Professor Lucia is gone from the laboratory.", 30);
    Sleep(500);

    dialog("Darius", "So you're basically working blind.", 30);
    Sleep(500);
    dialog("Elias", "Yes.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("A decision is made.\n", 30);
    Sleep(500);
    typing("They will continue the investigation together, without external interference.\n", 30);
    Sleep(500);

    typing("The next destination is decided: Rovenila.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Rovenila was once the central region of Ariolla Port.\n", 30);
    Sleep(500);
    typing("Now it is an unstable zone filled with residual Crimson activity.\n", 30);
    Sleep(500);
    typing("They move out immediately.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Upon arrival at Rovenila, the atmosphere is heavier than Ariolla Monument.\n", 30);
    Sleep(500);
    typing("Crimson residue is thinner... but more concentrated in unpredictable pockets.\n", 30);
    Sleep(500);

    typing("Another battle begins.\n", 30);
    Sleep(500);
    typing("This time, the creatures are faster and more adaptive.\n", 30);
    Sleep(500);
    typing("They learn mid-fight.\n", 30);
    Sleep(500);

    battle4(username);

    typing("But the trio manages to push through.\n", 30);
    Sleep(500);
    typing("Rovenila is temporarily secured.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "Rovenila used to be the central hub of Ariolla Port.", 30);
    Sleep(500);
    dialog("Elias", "If we rebuild it properly, it can become a research support base.", 30);
    Sleep(500);

    dialog("Ririsa", "A forward base for investigation?", 30);
    Sleep(500);
    dialog("Elias", "Exactly. A place where we can analyze, rest, and plan expansion safely.", 30);
    Sleep(500);

    dialog("Ririsa", "Then I'll ask Gary for support.", 30);
    Sleep(500);
    dialog("Ririsa", "If anyone can organize people for reconstruction, it's him.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "Before that... we need communication.", 30);
    Sleep(500);
    dialog("Darius", "Communication?", 30);
    Sleep(500);

    dialog("Elias", "We should build a Signal Transmission Tower.", 30);
    Sleep(500);
    dialog("Elias", "If something worse happens, we need a way to contact the outside world instantly.", 30);
    Sleep(500);

    dialog("Elias", "No delays. No messengers. No reliance on unstable routes.", 30);
    Sleep(500);
    dialog("Elias", "Direct transmission. Always online.", 30);
    Sleep(500);

    dialog("Ririsa", "Agreed.", 30);
    Sleep(500);
    dialog("Ririsa", "I'll bring it up to Gary as well.", 30);
    Sleep(500);

    dialog("Darius", "Then Rovenila becomes more than a battlefield.", 30);
    Sleep(500);
    dialog("Darius", "It becomes a command point.", 30);
    Sleep(500);

    typing("The next phase of the investigation begins.\n", 30);
    Sleep(500);
    typing("Rovenila will be rebuilt... not as a city, but as a system.\n", 30);
    Sleep(500);

    saveGame(username,1,10);
    return 0;
}

int chap1f(string username){
    system("cls");

    typing("ACT 3 - The Black-White Mystery", 50);
    Sleep(800);

    typing("The Signal Transmission Tower in Rovenila has finally been completed.\n", 30);
    Sleep(500);
    typing("Its metal structure stands above the ruins like a silent pillar connecting scattered hope across regions.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias immediately begins testing the communication system.\n", 30);
    Sleep(500);
    typing("She attempts to contact Demirgus Laboratory... specifically Professor Lucia.\n", 30);
    Sleep(500);

    dialog("Elias", "Professor Lucia... can you hear me?", 30);
    Sleep(500);

    typing("Static.\n", 30);
    Sleep(500);
    typing("No response.\n", 30);
    Sleep(500);
    typing("Only a silent transmission loop.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias tries again.\n", 30);
    Sleep(500);
    typing("And again.\n", 30);
    Sleep(500);
    typing("But Demirgus remains silent.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Before she can continue, Ririsa arrives in a hurry.\n", 30);
    Sleep(500);

    dialog("Ririsa", "Elias! I got news from Darius!", 30);
    Sleep(500);
    dialog("Ririsa", "He was sent to Moncini Basin for scouting.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Ririsa", "He saw something strange.", 30);
    Sleep(500);
    dialog("Ririsa", "A man in black-and-white clothing... wielding a sword.", 30);
    Sleep(500);
    dialog("Ririsa", "He was capturing an unconscious man in a lab coat.", 30);
    Sleep(500);

    dialog("Ririsa", "Darius said that the man in black-and-white suddenly asked to be brought here.", 30);
    Sleep(500);
    dialog("Ririsa", "Right now... he's in the armory with Darius.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias immediately decides to meet him.\n", 30);
    Sleep(500);
    typing("The unknown variable is too important to ignore.\n", 30);
    Sleep(500);

    typing("At the armory...\n", 30);
    Sleep(500);
    typing("Darius stands guard while the mysterious figure waits calmly.\n", 30);
    Sleep(500);

    dialog("Darius", "He's been asking to meet whoever is in charge.", 30);
    Sleep(500);

    typing("Before Elias can respond, Gary's voice comes through a nearby communicator.\n", 30);
    Sleep(500);

    dialog("Gary", "Just let Elias handle it. I'm too tired for this.", 30);
    Sleep(500);
    dialog("Gary", "Also I don't really want to walk all the way there.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias steps forward.\n", 30);
    Sleep(500);
    typing("The man slowly turns toward her.\n", 30);
    Sleep(500);

    dialog("Elias", "Who are you?", 30);
    Sleep(500);

    dialog("???", "...Kizuki.", 30);
    Sleep(500);

    dialog("Kizuki", "I didn't know anyone was still alive here.", 30);
    Sleep(500);
    dialog("Kizuki", "I thought this entire region had already been erased.", 30);
    Sleep(500);

    dialog("Ririsa", "We thought the same about everywhere else too.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias studies Kizuki carefully.\n", 30);
    Sleep(500);
    typing("His presence feels different from both survivors and corrupted beings.\n", 30);
    Sleep(500);

    dialog("Elias", "Where are you from?", 30);
    Sleep(500);

    dialog("Kizuki", "...", 30);
    Sleep(500);
    dialog("Kizuki", "I won't answer that.", 30);
    Sleep(500);

    typing("Silence fills the room.\n", 30);
    Sleep(500);

    dialog("Elias", "Then answer this instead.", 30);
    Sleep(500);
    dialog("Elias", "Why were you capturing that man?", 30);
    Sleep(500);
    dialog("Elias", "He looks like a survivor. A researcher maybe.", 30);
    Sleep(500);

    typing("Kizuki pauses.\n", 30);
    Sleep(500);
    typing("For the first time, his expression shifts slightly.\n", 30);
    Sleep(500);

    dialog("Kizuki", "...I was saving him.", 30);
    Sleep(500);

    typing("Elias narrows her eyes.\n", 30);
    Sleep(500);
    typing("The answer is too simple for something so suspicious.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "Then I propose something.", 30);
    Sleep(500);
    dialog("Elias", "Stay here. Both of you.", 30);
    Sleep(500);
    dialog("Elias", "Help us with our research on this phenomenon.", 30);
    Sleep(500);

    dialog("Elias", "In return, you'll be protected.", 30);
    Sleep(500);
    dialog("Elias", "And you can continue whatever you're doing... safely.", 30);
    Sleep(500);

    dialog("Kizuki", "...Agreed.", 30);
    Sleep(500);

    typing("No hesitation.\n", 30);
    Sleep(500);
    typing("No negotiation.\n", 30);
    Sleep(500);
    typing("Just acceptance.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    dialog("Elias", "I still need to speak with the man you captured.", 30);
    Sleep(500);

    dialog("Kizuki", "He's fine.", 30);
    Sleep(500);
    dialog("Kizuki", "And he'll agree with whatever I decide.", 30);
    Sleep(500);

    dialog("Elias", "...That's a strange thing to say.", 30);
    Sleep(500);

    typing("Elias does not press further.\n", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("As more data is gathered, Darius and Ririsa raise a new concern.\n", 30);
    Sleep(500);

    dialog("Darius", "If there are survivors like him out there...", 30);
    Sleep(500);
    dialog("Darius", "We need more space. More structure.", 30);
    Sleep(500);

    dialog("Ririsa", "Rovenila can't just be a base anymore.", 30);
    Sleep(500);
    dialog("Ririsa", "It needs to become a shelter.", 30);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias looks at the ruined city of Rovenila.\n", 30);
    Sleep(500);
    typing("Once the central district of Ariolla Port.\n", 30);
    Sleep(500);
    typing("Now a potential foundation for something new.\n", 30);
    Sleep(500);

    dialog("Elias", "Then we rebuild it properly.", 30);
    Sleep(500);

    dialog("Elias", "Not just a base.", 30);
    Sleep(500);
    dialog("Elias", "A central hub for survivors, research, and defense.", 30);
    Sleep(500);

    dialog("Elias", "Governor Manor.", 30);
    Sleep(500);

    dialog("Elias", "The old regional headquarters of Ariolla Port.", 30);
    Sleep(500);
    dialog("Elias", "We'll restore it and turn it into our main center.", 30);
    Sleep(500);

    dialog("Ririsa", "So... a capital for everything we're building?", 30);
    Sleep(500);

    dialog("Elias", "Yes.", 30);
    Sleep(500);
    dialog("Elias", "And if there are more survivors out there...", 30);
    Sleep(500);
    dialog("Elias", "They will find us here.", 30);
    Sleep(500);

    typing("The foundation of a new structured resistance begins in Rovenila.\n", 30);
    Sleep(500);
    typing("Governor Manor is set as the next major reconstruction target.\n", 30);
    Sleep(500);

    saveGame(username,1,12);
    return 0;
}

int chap1g(string username){
    system("cls");

    typing("ACT 4 - The Emerging Shadow", 50);
    Sleep(800);

    typing("Governor Manor has finally been restored.\n", 30);
    Sleep(500);
    typing("The former residence of Ariolla Port's governor now serves as the center of operations for Rovenila.\n", 30);
    Sleep(500);
    typing("Researchers, scouts, builders, and survivors now gather within its walls.\n", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("While organizing research documents inside her office, Elias receives a report.\n", 30);
    Sleep(500);

    dialog("Village Guard", "Miss Elias, the researcher Kizuki brought has regained consciousness.", 30);
    Sleep(500);
    dialog("Village Guard", "He's currently resting in the medical wing.", 30);
    Sleep(500);

    dialog("Elias", "Finally...", 30);
    Sleep(500);
    dialog("Elias", "Maybe he'll have some answers.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("Elias immediately leaves her office and heads toward the medical wing.\n", 30);
    Sleep(500);
    typing("However, before she reaches the hallway, someone steps into her path.\n", 30);
    Sleep(500);

    dialog("Kizuki", "Going somewhere?", 30);
    Sleep(500);
    dialog("Elias", "To meet your researcher.", 30);
    Sleep(500);
    dialog("Kizuki", "That can wait.", 30);
    Sleep(500);

    dialog("Elias", "Can it?", 30);
    Sleep(500);
    dialog("Kizuki", "Yes.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("Kizuki leans against a nearby pillar.\n", 30);
    Sleep(500);
    typing("For once, he looks willing to talk.\n", 30);
    Sleep(500);

    dialog("Kizuki", "You asked where I came from before.", 30);
    Sleep(500);
    dialog("Kizuki", "I'll answer now.", 30);
    Sleep(500);

    dialog("Kizuki", "There are still places in Morivelle that survived.", 30);
    Sleep(500);
    dialog("Kizuki", "Not everything was destroyed.", 30);
    Sleep(500);

    dialog("Elias", "That's impossible.", 30);
    Sleep(500);
    dialog("Elias", "We've found no functioning settlements outside this area.", 30);
    Sleep(500);

    dialog("Kizuki", "That's because you're looking in the wrong places.", 30);
    Sleep(500);

    dialog("Elias", "Then why hasn't anyone contacted the outside world?", 30);
    Sleep(500);

    dialog("Kizuki", "Because survival and civilization are two different things.", 30);
    Sleep(500);
    dialog("Kizuki", "Just because people survive doesn't mean they still have a society worth calling a nation.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("Elias studies Kizuki carefully.\n", 30);
    Sleep(500);
    typing("She still cannot determine whether he is being honest or simply manipulating the conversation.\n", 30);
    Sleep(500);

    dialog("Elias", "So you're saying there are still survivors out there?", 30);
    Sleep(500);
    dialog("Kizuki", "Yes.", 30);
    Sleep(500);
    dialog("Kizuki", "But we don't know which is a Yokai and which is a survivor.", 30);
    Sleep(500);
    dialog("Elias", "(Yokai? Gary mentioned something about that before...)", 30);
    Sleep(500);
    dialog("Elias", "What exactly is a Yokai?", 30);
    Sleep(500);
    dialog("Kizuki", "In my culture, Yokai are what we call the spirits of the land.", 30);
    Sleep(500);
    dialog("Kizuki", "They are the manifestations of nature's will.", 30);
    Sleep(500);
    dialog("Kizuki", "When something dies, its energy doesn't just disappear.", 30);
    Sleep(500);
    dialog("Kizuki", "It transforms into something else.", 30);
    Sleep(500);
    dialog("Elias", "How can you be so certain all of this is caused by spiritual creatures?", 30);
    Sleep(500);

    dialog("Kizuki", "Because that's what they are.", 30);
    Sleep(500);

    dialog("Elias", "That's not a scientific answer. It can't be proven.", 30);
    Sleep(500);

    dialog("Kizuki", "Then let's talk in science.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    dialog("Elias", "Everything I've seen suggests humans cannot adapt to Crimson Genesis.", 30);
    Sleep(500);
    dialog("Elias", "Cities collapse. Ecosystems mutate. People disappear.", 30);
    Sleep(500);
    dialog("Elias", "The survivors are either dead or transformed into monsters.", 30);
    Sleep(500);

    dialog("Kizuki", "Then you're looking at the wrong evidence.", 30);
    Sleep(500);

    dialog("Elias", "What do you mean?", 30);
    Sleep(500);

    dialog("Kizuki", "You're assuming adaptation means remaining human.", 30);
    Sleep(500);

    dialog("Elias", "What else would it mean?", 30);
    Sleep(500);

    dialog("Kizuki", "Exactly.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    dialog("Kizuki", "Tell me, Elias.", 30);
    Sleep(500);
    dialog("Kizuki", "What makes a person a person?", 30);
    Sleep(500);

    dialog("Elias", "Their consciousness. Their memories. Their identity.", 30);
    Sleep(500);

    dialog("Kizuki", "Good.", 30);
    Sleep(500);

    dialog("Kizuki", "Now imagine Crimson Genesis learns all of that.", 30);
    Sleep(500);

    dialog("Elias", "Learns?", 30);
    Sleep(500);

    dialog("Kizuki", "Every living thing leaves information behind.", 30);
    Sleep(500);
    dialog("Kizuki", "Instincts. Habits. Emotions. Memories.", 30);
    Sleep(500);

    dialog("Kizuki", "Your scientists already know that nature stores biological information.", 30);
    Sleep(500);
    dialog("Kizuki", "DNA is proof of that.", 30);
    Sleep(500);

    dialog("Kizuki", "What if Crimson Genesis stores something more?", 30);
    Sleep(500);

    dialog("Elias", "...", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    dialog("Kizuki", "Imagine a human dies.", 30);
    Sleep(500);
    dialog("Kizuki", "But their patterns remain.", 30);
    Sleep(500);

    dialog("Elias", "Patterns?", 30);
    Sleep(500);

    dialog("Kizuki", "Their fears.", 30);
    Sleep(500);
    dialog("Kizuki", "Their habits.", 30);
    Sleep(500);
    dialog("Kizuki", "Their memories.", 30);
    Sleep(500);
    dialog("Kizuki", "Everything that makes them who they are.", 30);
    Sleep(500);

    dialog("Kizuki", "Then Crimson Genesis creates something new using those patterns.", 30);
    Sleep(500);

    dialog("Elias", "A copy isn't the original.", 30);
    Sleep(500);

    dialog("Kizuki", "How would the copy know that?", 30);
    Sleep(500);

    dialog("Elias", "...", 30);
    Sleep(500);

    dialog("Kizuki", "If it remembers your childhood...", 30);
    Sleep(500);
    dialog("Kizuki", "Your family...", 30);
    Sleep(500);
    dialog("Kizuki", "Your dreams...", 30);
    Sleep(500);

    dialog("Kizuki", "At what point does it stop being you?", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    dialog("Elias", "You're describing imitation.", 30);
    Sleep(500);

    dialog("Kizuki", "Maybe.", 30);
    Sleep(500);

    dialog("Kizuki", "My people have another word for it.", 30);
    Sleep(500);

    dialog("Elias", "Yokai.", 30);
    Sleep(500);

    dialog("Kizuki", "Exactly.", 30);
    Sleep(500);

    dialog("Elias", "Spirits?", 30);
    Sleep(500);

    dialog("Kizuki", "No.", 30);
    Sleep(500);

    dialog("Kizuki", "Spirits are beliefs.", 30);
    Sleep(500);
    dialog("Kizuki", "Yokai are observations.", 30);
    Sleep(500);

    dialog("Kizuki", "A Yokai is what remains when a human adapts too well.", 30);
    Sleep(500);

    dialog("Elias", "You're saying the people of Morivelle aren't dead?", 30);
    Sleep(500);

    dialog("Kizuki", "I'm saying I'm not sure they are.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("Elias rubs her forehead.\n", 30);
    Sleep(500);
    typing("The theory sounds absurd.\n", 30);
    Sleep(500);
    typing("Yet somehow it explains certain inconsistencies she has encountered during her research.\n", 30);
    Sleep(500);

    dialog("Elias", "This conversation is giving me more questions than answers.", 30);
    Sleep(500);

    dialog("Kizuki", "Good.", 30);
    Sleep(500);
    dialog("Kizuki", "Questions keep people alive.", 30);
    Sleep(500);

    dialog("Elias", "We'll continue this later.", 30);
    Sleep(500);
    dialog("Elias", "I need to speak with that researcher now.", 30);
    Sleep(500);

    dialog("Kizuki", "...Good luck.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("A strange feeling suddenly runs through Elias.\n", 30);
    Sleep(500);
    typing("Without another word, she rushes toward the medical wing.\n", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("The room is empty.\n", 30);
    Sleep(500);
    typing("The bed is abandoned.\n", 30);
    Sleep(500);
    typing("The window is open.\n", 30);
    Sleep(500);

    dialog("Medical Staff", "Miss Elias!", 30);
    Sleep(500);
    dialog("Medical Staff", "The researcher woke up over an hour ago!", 30);
    Sleep(500);
    dialog("Medical Staff", "Then he suddenly ran away!", 30);
    Sleep(500);

    dialog("Elias", "What!?", 30);
    Sleep(500);

    dialog("Medical Staff", "He headed toward Moncini Basin.", 30);
    Sleep(500);
    dialog("Medical Staff", "Toward the deeper zones.", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("Elias clenches her fist.\n", 30);
    Sleep(500);
    typing("The one person who might possess critical information has escaped.\n", 30);
    Sleep(500);

    dialog("Elias", "Damn it...", 30);
    Sleep(500);
    dialog("Darius", "Why would he run!?", 30);
    Sleep(500);

    typing("Kizuki remains silent for several moments.\n", 30);
    Sleep(500);

    dialog("Kizuki", "Because he remembered.", 30);
    Sleep(500);

    dialog("Elias", "Remembered what?", 30);
    Sleep(500);

    dialog("Kizuki", "What he is.", 30);
    Sleep(500);

    dialog("Elias", "What are you talking about?", 30);
    Sleep(500);

    dialog("Kizuki", "The researcher isn't human.", 30);
    Sleep(500);

    dialog("Ririsa", "What!?", 30);
    Sleep(500);

    dialog("Kizuki", "Not anymore.", 30);
    Sleep(500);

    dialog("Elias", "You're saying he's a Yokai?", 30);
    Sleep(500);

    dialog("Kizuki", "I'm saying that's why I captured him.", 30);
    Sleep(500);

    dialog("Darius", "You never mentioned that part!", 30);
    Sleep(500);

    dialog("Kizuki", "Would any of you have believed me?", 30);
    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }
    system("cls");

    typing("Silence fills the room.\n", 30);
    Sleep(500);
    typing("Nobody has an answer.\n", 30);
    Sleep(500);

    typing("The researcher has disappeared into the depths of Moncini Basin.\n", 30);
    Sleep(500);
    typing("If Kizuki is correct, he may be far more than a survivor.\n", 30);
    Sleep(500);
    typing("If Elias is correct, he may possess the answers to Crimson Genesis itself.\n", 30);
    Sleep(500);
    typing("Either way, he cannot be allowed to disappear.\n", 30);
    Sleep(500);

    saveGame(username,1,14);
    return 0;
}


int chap1h1(string username){

    system("cls");

    typing("Elias wastes no time.\n",30);
    Sleep(500);
    typing("The escaped researcher may be the only person capable of answering the countless questions surrounding Crimson Genesis.\n",30);
    Sleep(500);
    typing("If he disappears into Moncini Basin, those answers may disappear with him.\n",30);

    Sleep(500);

    dialog("Elias","We're leaving now.",30);
    Sleep(500);
    dialog("Darius","Immediately?",30);
    Sleep(500);
    dialog("Elias","Every second matters.",30);
    Sleep(500);
    dialog("Ririsa","Then let's move!",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Moncini Basin, Ariolla Port, Morivelle City.\n",50);
    Sleep(500);
    typing("The deeper regions of the basin are unlike anything Elias has seen before.\n",30);
    Sleep(500);
    typing("Crimson roots crawl across the ground like veins.\n",30);
    Sleep(500);
    typing("The air itself feels alive.\n",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Several corrupted creatures emerge from the crimson fog.\n",30);
    Sleep(500);
    typing("Their bodies appear partially fused with aquatic organisms.\n",30);
    Sleep(500);
    typing("There is no choice but to fight.\n",30);
    Sleep(500);

    battle5(username);
    Sleep(500);

    system("cls");

    typing("After defeating the creatures, the group continues deeper into Moncini Basin.\n",30);
    Sleep(500);
    typing("The terrain becomes increasingly unstable.\n",30);
    Sleep(500);
    typing("Strange crimson growths cover the cliffs and waterways.\n",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    dialog("Ririsa","Do you really think we're going the right way?",30);
    Sleep(500);
    dialog("Elias","The tracks lead here.",30);
    Sleep(500);
    dialog("Darius","Then we keep moving.",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Eventually, they find him.\n",30);
    Sleep(500);
    typing("The researcher lies unconscious beside a shallow lake.\n",30);
    Sleep(500);
    typing("His breathing is weak.\n",30);

    Sleep(500);

    dialog("Elias","We found him.",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Elias kneels beside the researcher.\n",30);
    Sleep(500);
    typing("Searching his belongings, she discovers a damaged identification card.\n",30);

    Sleep(500);

    dialog("Elias","Aritha...",30);
    Sleep(500);
    dialog("Elias","His name is Aritha.",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("As Elias attempts to wake him, something feels wrong.\n",30);
    Sleep(500);
    typing("Aritha's skin is unnaturally red.\n",30);
    Sleep(500);
    typing("It looks as if the blood beneath his skin is trying to burst out.\n",30);

    Sleep(500);

    dialog("Ririsa","Elias... get away from him.",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Suddenly—\n",30);

    Sleep(300);

    dialog("Aritha","GHHHHHAAAAAA!!",30);

    Sleep(300);

    typing("Aritha lunges forward.\n",30);
    Sleep(500);
    typing("His teeth sink into Elias's shoulder.\n",30);

    Sleep(500);

    dialog("Elias","AAAAAHHH!!",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Ririsa immediately pushes Aritha away.\n",30);
    Sleep(500);
    typing("Elias collapses to her knees in agony.\n",30);

    Sleep(500);

    dialog("Darius","What the fuck?!",30);

    Sleep(500);

    typing("Aritha says nothing.\n",30);
    Sleep(500);
    typing("His eyes no longer resemble those of a human.\n",30);
    Sleep(500);
    typing("Without a word, he begins walking toward the lake.\n",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    dialog("Darius","Stop!",30);
    Sleep(500);

    typing("Aritha enters the water.\n",30);
    Sleep(500);
    typing("One step.\n",30);
    Sleep(500);
    typing("Two steps.\n",30);
    Sleep(500);
    typing("Three.\n",30);
    Sleep(500);

    typing("Then the lake begins to shake.\n",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Crimson energy erupts from beneath the surface.\n",30);
    Sleep(500);
    typing("Bones crack.\n",30);
    Sleep(500);
    typing("Flesh expands.\n",30);
    Sleep(500);
    typing("The lake itself seems to merge with Aritha's body.\n",30);

    Sleep(500);

    dialog("Ririsa","What... is that...?",30);

    Sleep(500);

    typing("A massive creature rises from the water.\n",30);
    Sleep(500);
    typing("A grotesque fusion of human remains, coral, scales, and crimson growths.\n",30);
    Sleep(500);
    typing("The researcher known as Aritha is gone.\n",30);

    Sleep(500);

    typing("Vessel of The Deep has emerged.\n",30);
    Sleep(500);
    
    boss(username);

    Sleep(500);

    
    if(waitOrSkip()) return 0;
    system("cls");

    typing("The battle is hopeless.\n",30);
    Sleep(500);
    typing("Every attack barely scratches the creature.\n",30);
    Sleep(500);
    typing("Its regeneration far exceeds anything the group has encountered.\n",30);

    Sleep(500);

    dialog("Darius","Fall back!!",30);

    Sleep(500);

    typing("Elias is severely wounded from Aritha's bite.\n",30);
    Sleep(500);
    typing("Ririsa suffers multiple fractures after protecting her.\n",30);

    Sleep(500);

    dialog("Ririsa","I can't move my leg...",30);

    Sleep(500);

    dialog("Darius","We're leaving. NOW!",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Several Night Raiders arrive as reinforcements.\n",30);
    Sleep(500);
    typing("Together they manage to evacuate Elias and Ririsa.\n",30);
    Sleep(500);
    typing("Behind them, Vessel of The Deep continues roaring across Moncini Basin.\n",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("At Rovenila.\n",30);

    Sleep(500);

    dialog("Gary","What happened to them!?",30);
    Sleep(500);

    dialog("Darius","The researcher transformed.",30);
    Sleep(500);
    dialog("Darius","He's become something far worse than a Yokai.",30);

    Sleep(500);

    dialog("Gary","Then Moncini Basin must be contained immediately.",30);
    Sleep(500);

    dialog("Gary","Gather every available engineer.",30);
    Sleep(500);
    dialog("Gary","I want artillery batteries facing the basin by tomorrow morning.",30);

    Sleep(500);

    dialog("Gary","No one enters Moncini Basin without authorization.",30);

    Sleep(500);

    typing("As healers rush Elias and Ririsa to the medical wing, a grim realization spreads across Rovenila.\n",30);
    Sleep(500);
    typing("The threat lurking within Morivelle is evolving.\n",30);
    Sleep(500);
    typing("And Aritha may only be the first Vessel.\n",30);

    Sleep(500);

    saveGame(username,1,16);

    return 0;
}

int chap1h2(string username){

    system("cls");

    typing("Elias stares toward the distant silhouette of Moncini Basin.\n",30);
    Sleep(500);
    typing("The researcher may possess valuable information.\n",30);
    Sleep(500);
    typing("Yet charging blindly into unknown territory could cost even more lives.\n",30);

    Sleep(500);

    dialog("Elias","No.",30);
    Sleep(500);
    dialog("Elias","We're not moving yet.",30);
    Sleep(500);

    dialog("Darius","What?",30);
    Sleep(500);

    dialog("Elias","I want more information first.",30);
    Sleep(500);
    dialog("Elias","If Kizuki knows something, I need answers from him before we act.",30);
    Sleep(500);

    dialog("Ririsa","That's... actually reasonable.",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Later that evening, Elias finds Kizuki sitting alone near the outer walls of Rovenila.\n",30);
    Sleep(500);
    typing("As always, he appears completely detached from everything around him.\n",30);

    Sleep(500);

    dialog("Elias","We need to talk.",30);
    Sleep(500);

    dialog("Kizuki","Then talk.",30);
    Sleep(500);

    dialog("Elias","You knew the researcher wasn't human.",30);
    Sleep(500);
    dialog("Elias","You knew something was wrong with him.",30);
    Sleep(500);

    dialog("Kizuki","Yes.",30);
    Sleep(500);

    dialog("Elias","Then explain.",30);

    Sleep(500);

    dialog("Kizuki","No.",30);
    Sleep(500);

    dialog("Elias","No?",30);
    Sleep(500);

    dialog("Kizuki","Not yet.",30);
    Sleep(500);

    dialog("Elias","People could die because of this.",30);
    Sleep(500);

    dialog("Kizuki","People die because of many things.",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    dialog("Elias","Stop speaking in riddles.",30);
    Sleep(500);

    dialog("Kizuki","Then stop asking questions you're not prepared to hear answers to.",30);
    Sleep(500);

    dialog("Elias","You know more than anyone here.",30);
    Sleep(500);

    dialog("Kizuki","I know enough to know ignorance is safer.",30);

    Sleep(500);

    dialog("Elias","What does that even mean?",30);
    Sleep(500);

    dialog("Kizuki","It means you'll understand later.",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Darius, who has been listening nearby, finally loses his patience.\n",30);

    Sleep(500);

    dialog("Darius","You're unbelievable.",30);
    Sleep(500);

    dialog("Darius","Every time someone asks you something important, you start talking like some prophet from a cheap religious cult.",30);
    Sleep(500);

    dialog("Darius","Either tell us what you know or stop pretending you're special.",30);

    Sleep(500);

    dialog("Kizuki","Interesting.",30);
    Sleep(500);

    dialog("Kizuki","The man who solves every problem with a knife thinks he's qualified to judge intelligence.",30);
    Sleep(500);

    dialog("Darius","What did you just say?",30);
    Sleep(500);

    dialog("Kizuki","You heard me.",30);
    Sleep(500);

    dialog("Kizuki","You're a guard dog that mistakes barking for thinking.",30);
    Sleep(500);

    dialog("Darius","Say that again.",30);
    Sleep(500);

    dialog("Kizuki","Why?",30);
    Sleep(500);

    dialog("Kizuki","Would repeating it improve your comprehension?",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Ririsa immediately steps between them.\n",30);
    Sleep(500);

    dialog("Ririsa","Okay! That's enough!",30);
    Sleep(500);

    dialog("Ririsa","Nobody's stabbing anybody today!",30);

    Sleep(500);

    dialog("Darius","This lunatic knows something and refuses to talk.",30);
    Sleep(500);

    dialog("Kizuki","Correct.",30);
    Sleep(500);

    dialog("Darius","I hate you.",30);
    Sleep(500);

    dialog("Kizuki","The feeling is surprisingly mutual.",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Without another word, Kizuki turns around and walks away.\n",30);
    Sleep(500);
    typing("Several moments later he disappears into the darkness beyond the walls.\n",30);

    Sleep(500);

    dialog("Elias","Wait—",30);
    Sleep(500);

    typing("Too late.\n",30);

    Sleep(500);

    dialog("Elias","He's gone...",30);
    Sleep(500);

    dialog("Ririsa","How does he keep doing that?",30);
    Sleep(500);

    dialog("Darius","Because he's annoying.",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Elias watches the darkness where Kizuki disappeared.\n",30);
    Sleep(500);
    typing("For the first time, she begins to seriously consider a possibility.\n",30);

    Sleep(500);

    dialog("Elias","Maybe he's the one person who actually understands what's happening.",30);
    Sleep(500);

    dialog("Ririsa","You trust him?",30);
    Sleep(500);

    dialog("Elias","No.",30);
    Sleep(500);

    dialog("Elias","But I think he knows something important.",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("To avoid taking unnecessary risks, Darius sends multiple Night Raider scouting teams into Moncini Basin.\n",30);
    Sleep(500);
    typing("Their mission is simple.\n",30);
    Sleep(500);
    typing("Observe. Report. Do not engage.\n",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Several days pass.\n",30);

    Sleep(500);

    typing("No reports arrive.\n",30);

    Sleep(500);

    typing("Then another day passes.\n",30);

    Sleep(500);

    typing("And another.\n",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("The silence ends when a wounded scout reaches Rovenila.\n",30);

    Sleep(500);

    dialog("Scout","Commander...!",30);
    Sleep(500);

    dialog("Scout","Moncini Basin...!",30);
    Sleep(500);

    dialog("Scout","Everyone's dead...!",30);

    Sleep(500);

    dialog("Darius","What happened!?",30);
    Sleep(500);

    dialog("Scout","A monster...!",30);
    Sleep(500);

    dialog("Scout","A giant sea monster...!",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("The scout collapses from exhaustion.\n",30);

    Sleep(500);

    dialog("Medic","He's suffering from severe shock.",30);

    Sleep(500);

    dialog("Scout","Twenty-one Night Raiders...",30);
    Sleep(500);

    dialog("Scout","It killed all twenty-one of them...",30);

    Sleep(500);

    dialog("Scout","It lives in the depths of Moncini Basin.",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Silence fills the command room.\n",30);

    Sleep(500);

    dialog("Ririsa","Twenty-one...?",30);
    Sleep(500);

    dialog("Darius","Impossible...",30);
    Sleep(500);

    dialog("Elias","A giant aquatic creature...",30);
    Sleep(500);

    dialog("Elias","Could it be the researcher?",30);

    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("Gary slowly stands from his chair.\n",30);

    Sleep(500);

    dialog("Gary","Enough.",30);
    Sleep(500);

    dialog("Gary","The situation has escalated beyond reconnaissance.",30);
    Sleep(500);

    dialog("Gary","Whether it's a Yokai, a mutant, or something else entirely doesn't matter anymore.",30);
    Sleep(500);

    dialog("Gary","It is a threat.",30);

    Sleep(500);

    dialog("Gary","Darius.",30);
    Sleep(500);

    dialog("Darius","Yes?",30);
    Sleep(500);

    dialog("Gary","Begin construction of defensive artillery around Moncini Basin immediately.",30);
    Sleep(500);

    dialog("Gary","I want firing positions established before the end of the week.",30);
    Sleep(500);

    dialog("Gary","If that creature leaves the basin, we stop it there.",30);

    Sleep(500);

    dialog("Darius","Understood.",30);
    Sleep(500);

    if(waitOrSkip()) return 0;
    system("cls");

    typing("The order spreads throughout Rovenila.\n",30);
    Sleep(500);
    typing("Engineers begin preparing heavy weapons.\n",30);
    Sleep(500);
    typing("Scouts map artillery positions.\n",30);
    Sleep(500);
    typing("Night Raiders ready themselves for a war they do not understand.\n",30);

    Sleep(500);

    typing("Meanwhile, somewhere beyond the crimson waters of Moncini Basin...\n",30);
    Sleep(500);
    typing("Something enormous moves beneath the surface.\n",30);

    Sleep(500);

    saveGame(username,1,18);

    return 0;
}

int chap1i(string username){
    system("cls");

    typing("ACT 5 - Ariolla's Truth", 50);
    Sleep(800);

    typing("Several months have passed since the incident at Moncini Basin.\n",30);
    Sleep(500);
    typing("Despite countless investigations, Elias has found almost no new answers.\n",30);
    Sleep(500);
    typing("The giant creature known as Vessel of The Deep continues to lurk within Moncini Basin.\n",30);
    Sleep(500);
    typing("Its existence alone has forced Ariolla Port to remain on constant alert.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Late at night.\n",30);
    Sleep(500);
    typing("Inside Governor Manor.\n",30);
    Sleep(500);
    typing("Elias sits alone, reviewing research notes.\n",30);
    Sleep(500);
    typing("A headache slowly builds behind her eyes.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("The door suddenly opens.\n",30);
    Sleep(500);

    dialog("Elias","Kizuki?",30);
    Sleep(500);

    typing("Without answering, Kizuki walks inside.\n",30);
    Sleep(500);
    typing("He closes the door.\n",30);
    Sleep(500);
    typing("Then locks it.\n",30);
    Sleep(500);
    typing("Then seals the windows.\n",30);
    Sleep(500);

    dialog("Elias","...What are you doing?",30);
    Sleep(500);

    dialog("Kizuki","Making sure nobody hears this conversation.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","I've had enough of your cryptic behavior.",30);
    Sleep(500);
    dialog("Elias","If you know something, say it already.",30);
    Sleep(500);

    dialog("Kizuki","That's exactly why I'm here.",30);
    Sleep(500);

    dialog("Kizuki","Because you're finally asking the right questions.",30);
    Sleep(500);

    dialog("Elias","Then answer them.",30);
    Sleep(500);

    dialog("Kizuki","Very well.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Kizuki","Everything you've learned about Crimson Genesis is incomplete.",30);
    Sleep(500);

    dialog("Kizuki","And the biggest misunderstanding is standing right outside this building.",30);
    Sleep(500);

    dialog("Elias","What do you mean?",30);
    Sleep(500);

    dialog("Kizuki","The Night Raiders.",30);
    Sleep(500);

    dialog("Elias","What about them?",30);
    Sleep(500);

    dialog("Kizuki","They are Yokai.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","...What?",30);
    Sleep(500);

    dialog("Kizuki","The Night Raiders are Yokai.",30);
    Sleep(500);

    dialog("Kizuki","Every single one of them.",30);
    Sleep(500);

    dialog("Elias","That's impossible.",30);
    Sleep(500);

    dialog("Elias","They're human.",30);
    Sleep(500);

    dialog("Kizuki","No.",30);
    Sleep(500);

    dialog("Kizuki","They're simply aware of what they are.",30);
    Sleep(500);

    dialog("Kizuki","Most Yokai never realize it.",30);
    Sleep(500);

    dialog("Kizuki","The Night Raiders do.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Kizuki","You want to know why they can purify Crimson Genesis?",30);
    Sleep(500);

    dialog("Elias","Yes.",30);
    Sleep(500);

    dialog("Kizuki","Because they were born from it.",30);
    Sleep(500);

    dialog("Elias","What?",30);
    Sleep(500);

    dialog("Kizuki","Crimson Genesis isn't merely a disaster.",30);
    Sleep(500);

    dialog("Kizuki","It is also the source of their existence.",30);
    Sleep(500);

    dialog("Kizuki","The reason they can cleanse corruption is because they are part of the phenomenon itself.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Kizuki","You've spent years searching for a cure.",30);
    Sleep(500);

    dialog("Kizuki","A super antidote.",30);
    Sleep(500);

    dialog("Kizuki","A miracle technology.",30);
    Sleep(500);

    dialog("Kizuki","A scientific solution.",30);
    Sleep(500);

    dialog("Kizuki","But the answer was standing in front of you all along.",30);
    Sleep(500);

    dialog("Kizuki","Crimson Genesis is fought using Crimson Genesis.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Elias feels her chest tighten.\n",30);
    Sleep(500);

    dialog("Elias","Then Ririsa...",30);
    Sleep(500);

    dialog("Elias","Darius...",30);
    Sleep(500);

    dialog("Elias","Gary...",30);
    Sleep(500);

    dialog("Elias","They're all Yokai?",30);
    Sleep(500);

    dialog("Kizuki","Yes.",30);
    Sleep(500);

    dialog("Elias","And they've known this the entire time?",30);
    Sleep(500);

    dialog("Kizuki","Most likely.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","Then what about you?",30);
    Sleep(500);

    dialog("Elias","Your abilities...",30);
    Sleep(500);

    dialog("Elias","Are those from Crimson Genesis too?",30);
    Sleep(500);

    dialog("Kizuki","No.",30);
    Sleep(500);

    dialog("Kizuki","I'm still human.",30);
    Sleep(500);

    dialog("Kizuki","Everything I can do was learned.",30);
    Sleep(500);

    dialog("Kizuki","Not inherited.",30);
    Sleep(500);

    dialog("Elias","That's somehow even more disturbing.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Kizuki","There's something else.",30);
    Sleep(500);

    dialog("Kizuki","I want you to come with me.",30);
    Sleep(500);

    dialog("Elias","Come where?",30);
    Sleep(500);

    dialog("Kizuki","To the place I came from.",30);
    Sleep(500);

    dialog("Kizuki","A place where survivors still exist.",30);
    Sleep(500);

    dialog("Kizuki","A place outside Ariolla.",30);
    Sleep(500);

    dialog("Kizuki","A place that needs your help.",30);
    Sleep(500);

    dialog("Elias","Why me?",30);
    Sleep(500);

    dialog("Kizuki","Because you're smart.",30);
    Sleep(500);

    dialog("Kizuki","And because I need help solving a problem involving someone named Hiyuki.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","I can't leave.",30);
    Sleep(500);

    dialog("Elias","Not now.",30);
    Sleep(500);

    dialog("Elias","Vessel of The Deep is still alive.",30);
    Sleep(500);

    dialog("Elias","Ariolla Port is still in danger.",30);
    Sleep(500);

    dialog("Kizuki","And that's exactly why you should leave.",30);
    Sleep(500);

    dialog("Elias","What?",30);
    Sleep(500);

    dialog("Kizuki","Because the Night Raiders themselves may become the next problem.",30);
    Sleep(500);

    dialog("Kizuki","And Vessel of The Deep will only amplify the chaos.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","Then let's kill Aritha first.",30);
    Sleep(500);

    dialog("Kizuki","Impossible.",30);
    Sleep(500);

    dialog("Elias","Nothing is impossible.",30);
    Sleep(500);

    dialog("Kizuki","You're underestimating what that creature has become.",30);
    Sleep(500);

    dialog("Elias","Maybe.",30);
    Sleep(500);

    dialog("Elias","But if you help me destroy Vessel of The Deep...",30);
    Sleep(500);

    dialog("Elias","I'll go with you afterwards.",30);
    Sleep(500);

    dialog("Elias","I'll help you solve whatever problem Hiyuki has created.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Kizuki remains silent.\n",30);
    Sleep(500);
    typing("For several moments he simply stares at Elias.\n",30);
    Sleep(500);

    dialog("Kizuki","...A fair deal.",30);
    Sleep(500);

    dialog("Kizuki","Very well.",30);
    Sleep(500);

    dialog("Kizuki","I'll help you destroy Aritha.",30);
    Sleep(500);

    dialog("Elias","Then we have an agreement.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","For now, trust the Night Raiders.",30);
    Sleep(500);

    dialog("Kizuki","You're asking a lot.",30);
    Sleep(500);

    dialog("Elias","And I'll keep their secret.",30);
    Sleep(500);

    dialog("Elias","No one else needs to know about this.",30);
    Sleep(500);

    dialog("Kizuki","...Fine.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("The two leave the room.\n",30);
    Sleep(500);
    typing("Moments later they gather Gary, Ririsa, and Darius.\n",30);
    Sleep(500);

    dialog("Elias","We have a target.",30);
    Sleep(500);

    dialog("Elias","We're eliminating Vessel of The Deep.",30);
    Sleep(500);

    dialog("Ririsa","Finally!",30);
    Sleep(500);

    dialog("Gary","Then it's time.",30);
    Sleep(500);

    dialog("Darius","And the mysterious monk finally decided to help?",30);
    Sleep(500);

    dialog("Darius","I thought your main skill was standing dramatically in corners.",30);
    Sleep(500);

    dialog("Kizuki","Someone has to compensate for your incompetence.",30);
    Sleep(500);

    dialog("Darius","What was that!?",30);
    Sleep(500);

    dialog("Kizuki","You heard me.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","Enough!",30);
    Sleep(500);

    dialog("Elias","Both of you.",30);
    Sleep(500);

    dialog("Elias","Save it for after we survive this.",30);
    Sleep(500);

    dialog("Ririsa","I agree with Elias.",30);
    Sleep(500);

    dialog("Ririsa","Please don't destroy the room before the monster does.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Preparations begin immediately.\n",30);
    Sleep(500);
    typing("Scouts are recalled.\n",30);
    Sleep(500);
    typing("Weapons are prepared.\n",30);
    Sleep(500);
    typing("The Night Raiders gather their strongest fighters.\n",30);
    Sleep(500);
    typing("And for the first time...\n",30);
    Sleep(500);
    typing("Kizuki joins the operation.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("The final battle against Vessel of The Deep is approaching.\n",30);
    Sleep(500);

    saveGame(username,1,20);
    return 0;
}

int chap1j(string username){
    system("cls");

    typing("Vessel of The Deep lets out one final scream.\n",30);
    Sleep(500);
    typing("Its massive body begins to crack apart.\n",30);
    Sleep(500);
    typing("Crimson energy escapes from countless fractures across its body.\n",30);
    Sleep(500);
    typing("Then the creature collapses into the waters of Moncini Basin.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Silence.\n",30);
    Sleep(500);
    typing("For several seconds nobody moves.\n",30);
    Sleep(500);
    typing("Nobody speaks.\n",30);

    Sleep(500);

    dialog("Ririsa","...",30);
    Sleep(500);
    dialog("Darius","...",30);
    Sleep(500);
    dialog("Elias","...",30);

    Sleep(500);

    dialog("Ririsa","WE WON!!",30);

    Sleep(500);

    dialog("Darius","HAHAHAHA!! IT'S DEAD!",30);
    Sleep(500);

    dialog("Night Raiders","VICTORY!!",30);
    Sleep(500);
    dialog("Night Raiders","WE DID IT!",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("The battlefield erupts into celebration.\n",30);
    Sleep(500);
    typing("Months of fear and uncertainty finally come to an end.\n",30);
    Sleep(500);
    typing("The monster that haunted Ariolla Port has been defeated.\n",30);

    Sleep(500);

    dialog("Ririsa","It's over...",30);
    Sleep(500);
    dialog("Ririsa","It's finally over...",30);
    Sleep(500);

    dialog("Elias","Yeah.",30);
    Sleep(500);
    dialog("Elias","We did it.",30);
    Sleep(500);

    dialog("Darius","And we survived somehow.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("That evening, everyone returns to Rovenila.\n",30);
    Sleep(500);
    typing("The Governor Manor is transformed into a celebration hall.\n",30);
    Sleep(500);
    typing("Food is prepared.\n",30);
    Sleep(500);
    typing("Music is played.\n",30);
    Sleep(500);
    typing("For the first time in months, people allow themselves to smile.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Ririsa","Come on Elias!",30);
    Sleep(500);
    dialog("Ririsa","Tonight we're celebrating!",30);
    Sleep(500);

    dialog("Elias","I know, I know.",30);
    Sleep(500);

    dialog("Darius","You deserve it more than anyone.",30);
    Sleep(500);

    dialog("Gary","Without you, none of this would've happened.",30);
    Sleep(500);

    dialog("Elias","It wasn't just me.",30);
    Sleep(500);

    dialog("Elias","We all fought for this.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Hours pass.\n",30);
    Sleep(500);
    typing("The celebration grows louder.\n",30);
    Sleep(500);
    typing("Until someone quietly taps Elias's shoulder.\n",30);

    Sleep(500);

    dialog("Kizuki","Come with me.",30);
    Sleep(500);

    dialog("Elias","Now?",30);
    Sleep(500);

    dialog("Kizuki","Now.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Kizuki leads Elias away from the celebration.\n",30);
    Sleep(500);
    typing("Far from the lights.\n",30);
    Sleep(500);
    typing("Far from the music.\n",30);
    Sleep(500);
    typing("Into a quiet corner of Rovenila.\n",30);

    Sleep(500);

    dialog("Kizuki","I'm here to collect your promise.",30);
    Sleep(500);

    dialog("Elias","You really don't waste any time.",30);
    Sleep(500);

    dialog("Kizuki","Time is precious.",30);
    Sleep(500);

    dialog("Elias","I'll go.",30);
    Sleep(500);

    dialog("Elias","Just let me wait until everyone falls asleep.",30);
    Sleep(500);

    dialog("Kizuki","Fine.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("The night grows deeper.\n",30);
    Sleep(500);
    typing("One by one, the celebration fades.\n",30);
    Sleep(500);
    typing("The Night Raiders return to their homes.\n",30);
    Sleep(500);
    typing("Eventually, even Ririsa falls asleep.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Elias remains awake.\n",30);
    Sleep(500);
    typing("Sitting alone beneath a lantern.\n",30);

    Sleep(500);

    typing("She takes out a notebook.\n",30);
    Sleep(500);
    typing("And begins writing.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("To Ririsa.\n\n",30);
    Sleep(500);

    typing("Thank you for everything.\n",30);
    Sleep(500);
    typing("I'm sorry for leaving without saying goodbye.\n",30);
    Sleep(500);
    typing("I know you'll probably be angry when you read this.\n",30);

    Sleep(500);

    typing("Please take everyone back to the Village of Purification.\n",30);
    Sleep(500);
    typing("Keep them safe.\n",30);
    Sleep(500);

    typing("I need to continue my investigation.\n",30);
    Sleep(500);
    typing("There are still too many unanswered questions.\n",30);
    Sleep(500);

    typing("Kizuki knows something.\n",30);
    Sleep(500);
    typing("Maybe he knows the truth behind everything.\n",30);

    Sleep(500);

    typing("I promise I'll come back.\n",30);
    Sleep(500);
    typing("And when I do, I'll explain everything.\n",30);
    Sleep(500);

    typing("Your friend,\n",30);
    Sleep(500);
    typing("Elias.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Elias places the letter beside Ririsa's bed.\n",30);
    Sleep(500);

    typing("Then quietly leaves Governor Manor.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("Outside the city walls.\n",30);
    Sleep(500);

    typing("Kizuki is already waiting.\n",30);

    Sleep(500);

    dialog("Kizuki","Ready?",30);
    Sleep(500);

    dialog("Elias","As ready as I'll ever be.",30);

    Sleep(500);

    dialog("Kizuki","Good.",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("The two begin walking into the darkness.\n",30);
    Sleep(500);

    typing("Leaving Ariolla behind.\n",30);
    Sleep(500);

    typing("Leaving answers behind.\n",30);
    Sleep(500);

    typing("And moving toward even greater mysteries.\n",30);

    Sleep(500);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    dialog("Elias","One last question.",30);
    Sleep(500);

    dialog("Kizuki","Hmm?",30);
    Sleep(500);

    dialog("Elias","What is the name of this place we're going to?",30);

    Sleep(500);

    dialog("Kizuki","A beautiful place.",30);
    Sleep(500);

    dialog("Kizuki","A land filled with sakura trees.",30);
    Sleep(500);

    dialog("Kizuki","A city where the old world refused to die.",30);

    Sleep(500);

    dialog("Kizuki","Kireinara.",30);

    Sleep(1000);

    if(waitOrSkip()){
        return 0;
    }

    system("cls");

    typing("END OF CHAPTER 1\n",50);
    Sleep(1000);

    typing("Next Chapter : The Sakura City of Kireinara\n",50);
    Sleep(500);

    saveGame(username,1,21);
    return 0;
}

int chap1(int scene, string username)
{
    PlayerData p = loadPlayer(username);

    if(scene <= 1) chap1a(username);
    if(scene <= 2){
        saveGame(username,1,2);
        bsp(username);
    }
    if(scene <= 3) chap1b(username);
    if(scene <= 4){
        saveGame(username,1,4);
        mc(username);
    }
    if(scene <= 5) chap1c(username);
    if(scene <= 6){
        saveGame(username,1,6);
        battle1(username);

        scene = 7;
    }
    if(scene == 7){
        chap1d(username);
        bool hasRirisa = false;
        bool hasDarius = false;
        for(auto &c : p.ownedCharacters){
            if(c.name == "Ririsa") hasRirisa = true;
            if(c.name == "Darius") hasDarius = true;
        }
        if(!hasRirisa) {
            giveCharacter(username,"Ririsa");
            cout << "\n=================================\n";
            cout << " New Character Unlocked!\n";
            cout << " You can now play as Ririsa!\n";
            cout << "=================================\n";
            system("pause");
        }
        if(!hasDarius) {
            giveCharacter(username,"Darius");
            cout << "\n=================================\n";
            cout << " New Character Unlocked!\n";
            cout << " You can now play as Darius!\n";
            cout << "=================================\n";
            system("pause");
        }
        scene = 8;
    }
    if(scene == 8){
        saveGame(username,1,8);
        mainCity(username,1,8);
    }
    membaca(username);
    if(!act1()) return 0;
    if(quit=='y'||quit=='Y') return 0;
    if(scene <= 9) {chap1e(username);
        scene = 10;
    }
    if(scene == 10){
        daerah[2].unlock = true;
        daerah[3].unlock = true;
        updateBuilding(username);
        saveGame(username,1,10);
        mainCity(username,1,10);
    }
    membaca(username);
    if(!act2()) return 0;
    if(quit=='y'||quit=='Y') return 0;
    if(scene <= 11){
        chap1f(username);
        scene = 12;
    }
    if(scene == 12){
        saveGame(username,1,12);
        mainCity(username,1,12);
        scene = 13;
    }
    membaca(username);
    if(!act3()) return 0;
    if(quit=='y'||quit=='Y') return 0;
    if(scene == 13) {
        chap1g(username);
        scene = 14;
    }
    if(scene == 14){
        int nextScene = choosePath();
        saveGame(username,1,nextScene);
        scene = nextScene;
    }
    if(scene == 15){
        chap1h1(username);
        scene = 16;
    }
    if(scene == 16){
        daerah[4].unlock = true;
        updateBuilding(username);
        saveGame(username,1,16);
        mainCity(username,1,16);
        scene = 19;
    }
    if(scene == 17) {
        chap1h2(username);
        scene = 18;
    }
    if(scene == 18){
        daerah[4].unlock = true;
        updateBuilding(username);
        saveGame(username,1,18);
        mainCity(username,1,18);
        scene = 19;
    }
    membaca(username);
    if(!act4()) return 0;
    if(quit=='y'||quit=='Y') return 0;
    if(scene == 19) {
        chap1i(username);
        bool hasKizuki = false;
        for(auto &c : p.ownedCharacters){
            if(c.name == "Kizuki") hasKizuki = true;
        }
        if(!hasKizuki) {
            giveCharacter(username,"Kizuki");
            cout << "\n=================================\n";
            cout << " New Character Unlocked!\n";
            cout << " You can now play as Kizuki!\n";
            cout << "=================================\n";
            system("pause");
        }
        scene = 20;
    }
    if(scene == 20){
        saveGame(username,1,20);
        boss2(username);
        scene = 21;
    }
    if(scene == 21) chap1j(username);
    return 0;
}