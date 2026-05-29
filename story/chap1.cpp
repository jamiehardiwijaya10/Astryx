#include <iostream>
#include <windows.h>
#include "../miniGames/memoryCard.cpp"
using namespace std;


int chap1a(string username){
    system("cls");
    typing("CHAPTER 1 - RETURN TO MORIVELLE", 100);
    Sleep(800);
    
    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("ACT 1 - The Night Raiders", 100);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ariolla Monument, Ariolla Port, Morivelle City.", 100);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("23 September 1891", 40);
    typing("10.51 PM", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("After traveling for 14 hours from Elpis Harbor, Elias arrives in Morivelle.", 40);
    typing("Specifically at Ariolla Port, which was once the center of tourist arrivals to Morivelle and 1 of the 5 major regions in Morivelle", 40);
    typing("\"Is this... A-Ariolla Port?\"", 40);
    typing("\"W-What happened here?\"", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ariolla Port, which was once thriving with tourists, has become a desolate dead city. Buildings that were once magnificent are now destroyed and filled with wild plants.", 40);
    typing("The harbor, which was once full of ships, is now empty and filled with scattered garbage.", 40);
    typing("Elias walks through the harbor with mixed emotions of sadness, anger, and confusion.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"The Red Tide phenomenon hasn't been able to cause such massive destruction.\"", 40);
    typing("\"Is this the peak of destruction from The Red Tide?\"", 40);
    typing("Putting aside her emotions, Elias goes to find out what happened to her hometown", 40);
    typing("She begins searching for information by examining the buildings that still stand, looking for clues about what happened at Ariolla Monument.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias finds a locked box.", 40);
    typing("Elias tries to open the box\n", 40);

    typing("Notice: You will enter a mini-game to open the box. If you win, you can continue the story. Try your best to win this mini-game!", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");    

    saveGame(username,1,2);
    return 0;
}

int chap1b(string username){
    system("cls");
    typing("The box opens!", 40);
    typing("The box is empty. Elias feels disappointed.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias tries to continue his investigation deeper into the main Ariolla monument.", 40);
    typing("This monument stands majestically in the Ariolla Monument area, with a large statue depicting a woman holding a crystal ball.", 40);
    typing("The statue looks very old and is already beginning to deteriorate, with many parts missing or broken.", 40);
    typing("This monument was named Ariolla after a female hero who once saved Morivelle from pirate attacks in the 17th century.", 40);
    typing("Elias examines the statue carefully, trying to find clues about what happened at Ariolla.\n", 40);

    typing("Notice: You will enter a mini-game to examine clues on the statue. If you win, you can continue the story. Try your best to win this mini-game!", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");    

    saveGame(username,1,4);
    return 0;
}

int chap1c(string username){
    system("cls");
    typing("The statue is successfully analyzed!\n", 40);
    typing("From the analysis results, Elias discovers that the damage that occurred at Ariolla Port seems to come from one direction.", 40);
    typing("This damage appears to come from the northwest direction, which means in all likelihood the damage comes from the direction of Morivelle City center.", 40);
    typing("Elias decides to go northwest.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Rovenila, Ariolla Port, Morivelle City.", 40);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias arrives at Rovenila, an area that was once the center of government for the Ariolla Port region", 40);
    typing("This area was once filled with magnificent government buildings, but now has turned into desolate ruins filled with wild plants.", 40);
    typing("Elias begins exploring this area, looking for clues about what happened at Ariolla.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("As Elias walks through the streets of Rovenila, a creature appears from behind the ruins. This creature looks like a human, but with red skin and glowing eyes.", 40);
    typing("The creature approaches Elias with slow but steady steps, like a normal human walking, but the aura emanating from this creature is very frightening and intimidating.", 40);
    typing("Driven by curiosity and great intrigue, Elias decides to approach the creature, hoping to get clues about what happened at Ariolla.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias approaches the creature carefully, trying not to arouse suspicion or threat to the creature.", 40);
    typing("However, as Elias gets closer, the creature also approaches Elias with stumbling steps, as if the creature is also curious about Elias.", 40);
    typing("When the two are close enough, the creature suddenly attacks Elias", 40);
    typing("Armed with a handgun and quick reflexes, Elias successfully dodges the attack and retaliates by shooting the creature several times.", 40);
    typing("However, the sound of gunfire echoes throughout Rovenila, drawing the attention of similar creatures hidden behind the ruins.\n", 40);
    typing("Notice: You will enter a battle to fight the creature. If you win, you can continue the story. Try your best to win this battle!", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,6);
    return 0;

}

int chap1d(string username){
    system("cls");
    typing("Elias successfully defeats the creature!\n", 40);
    typing("After defeating the creature, Elias glances at the creature's body to look for clues about what happened at Ariolla.", 40);
    typing("However, as more similar creatures appear, Elias decides to quickly leave Rovenila and return to Ariolla Monument.", 40);
    typing("She plans to return first to Demirgus and make preparations for a major investigation at Ariolla.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Without clarity, Ariolla Monument becomes filled with similar creatures. There is also a very large creature.", 40);
    typing("This large creature has dark red skin, like a human with its skin ripped off. Its mouth is wide with sharp teeth and a long tongue", 40);
    typing("Seeing no way out, Elias decides to go south, trying to reach the other side of the beach to find a way out of Ariolla.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias successfully enters the forest on the south side of Rovenila. After running for a while, he can catch his breath and tries to find a way out of the forest.", 40);
    typing("Elias finds a small hut that looks like a dwelling. The hut looks like a guard post and its condition is still well maintained, unlike the surrounding area which is already destroyed.", 40);
    typing("Elias decides to approach the hut, hoping to find clues about what happened at Ariolla.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("As Elias approaches the hut, he sees a man and a woman talking inside. They look like normal humans, but the aura they emanate is very different from the similar creatures in Rovenila.", 40);
    typing("Elias decides to approach them carefully, trying not to arouse suspicion or threat to them.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Elias approaches them and tries to start a conversation. However, the man suddenly points a knife at Elias.\n", 40);
    typing("\"Who are you!?\" the man asks with a harsh and suspicious voice.\n", 40);
    typing("\"I... I'm here to go home to Morivelle...\" Elias answers with a trembling voice.\n", 40);
    typing("\"I come from Morivelle...\" Elias continues, trying to convince the man.\n", 40);
    typing("\"I came from Demirgus...\" Elias adds, hoping to convince the man that she is not a threat to them.", 40);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("The man looks hesitant, but the woman next to him approaches Elias.", 40);
    typing("She forcibly examines Elias's hand, trying to find clues about who Elias really is.", 40);
    typing("After a while, the woman seems satisfied with what she finds on Elias's hand.\n", 40);
    typing("\"At least you're not part of them...\" the woman says with a softer voice.\n", 40);
    typing("\"But your identity... You should come with us...\" the woman continues, trying to convince Elias to go with them.\n", 40);
    typing("\"What are you doing Ririsa?\" the man asks with a confused voice, seeming to disagree with the woman's decision.\n", 40);
    typing("\"You said you came from Demirgus, didn't you?\" the woman says, trying to convince the man that Elias is not a threat to them.\n", 40);
    typing("\"You also said you're here to go home to Morivelle, didn't you?\" the woman clarifies.\n", 40);
    typing("\"Simple, the conclusion is she's a native Morivelle citizen who went to Demirgus to work, but now she's coming back to Morivelle...\" the woman continues, trying to convince the man that Elias is not a threat to them.\n", 40);
    typing("\"Actually, to study.\" Elias says.\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"You see...\" the woman says, trying to convince the man that Elias is not a threat to them.\n", 40);
    typing("The man slowly lowers his knife.", 40);
    typing("\"Okay.\" the man says with a still hesitant voice, but he seems more calm than before.\n", 40);
    typing("\"Sorry hehe... My husband is a bit paranoid about security, especially with the current situation.\" the woman says, trying to calm Elias.\n", 40);
    typing("\"My name is Ririsa, this is my husband, Darius.\" the woman says, introducing herself and her husband to Elias.\n", 40);
    typing("\"You can come with us. For the safety of our village and also to possibly answer your confusion.\" Ririsa says firmly, trying to convince Elias to go with them.\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ririsa and Elias go to the village in the forest, leaving Darius at the guard post.", 40);
    typing("While walking towards the village, Elias asks Ririsa.\n");
    typing("\"How are you...\" Elias asks.\n", 40);
    typing("\"From your situation and your explanation, it's clear what your condition is now. You're confused about what's happening here.\" Ririsa answers before Elias can finish his question.\n", 40);
    typing("\"You come from a village? I don't remember a village in this area.\"\n", 40);
    typing("\"How long ago did you leave Morivelle?\"\n", 40);
    typing("\"Almost 5 years ago\" Elias answers.\n", 40);
    typing("\"Hmm... No wonder. We didn't exist 5 years ago.\n", 40);
    typing("\"So you...?\"\n");
    typing("\"Yup. You guessed it. We're not from Morivelle. We're immigrants from far away.\" Ririsa answers cheerfully with a smile.\n", 40);
    typing("\"You're so cheerful and not reluctant to give information like this.\" Elias says to clarify.\n", 40);
    typing("\"Why would that be? I like talking to someone my age. It's rare that I have a female friend my age.\" Ririsa clarifies more cheerfully.\n", 40);
    typing("\"Oh...\" Elias answers shortly, hesitant to continue the topic\n", 40);
    typing("Soon after, they arrive at the village.");
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Village of Purification, Ariolla Port, Morivelle City.", 100);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"Welcome to the village of The Night Raiders or as outsiders call it, the Village of Purification\"\n");
    typing("\"The Night Raiders? Village of Purification?\" Elias asks.\n", 40);
    typing("\"Ah... The Night Raiders is the name for our people.\" Ririsa explains cheerfully.\n", 40);
    typing("\"We are a nomadic people. We lived island to island. Now we live here. But because of some situations and current conditions, it seems we will continue to live here.\" Ririsa adds, looking a bit thoughtful.\n", 40);
    typing("Hesitant to ask, Elias just falls silent and doesn't dare continue the conversation\n", 40);
    typing("\"Well... That's not too important. As for this village itself, it's named Village of Purification because this area was very contaminated in the past.\" Ririsa continues more cheerfully.\n", 40);
    typing("\"The Night Raiders have a special ability in purification or cleansing. We can clean contaminated water, soil, and air with our abilities.\" Ririsa explains proudly.\n", 40);
    typing("\"Not only that, we can also clean living creatures that are contaminated with our abilities.\" Ririsa adds, seeming a bit uncertain.\n", 40);
    typing("\"Living creatures that are contaminated?\" Elias asks curiously.\n", 40);
    typing("\"Yes, living creatures that are contaminated with black spots that we're trying to figure out. We can clean them with our abilities.\" Ririsa explains, seeming a bit uncertain.\n", 40);
    typing("\"Black spots?\" Elias asks curiously.\n", 40);
    typing("\"Yes, black spots are like stains that appear on the skin of living creatures. We don't know what causes it yet, but we suspect it's some kind of infection or disease caused by some phenomenon.\" Ririsa explains, seeming a bit uncertain.\n", 40);
    typing("\"Phenomenon? Do you mean The Red Tide?\" Elias asks curiously.", 40);
    typing("\"The Red Tide? What is that?\" Ririsa asks.\n", 40);
    typing("\"Emm... It's just my theory, I can explain it later at the right time.\" Elias answers, hesitant to continue the topic\n", 40);
    typing("\"Okay then, we can talk about that later. Anyway, that's why this village is named Village of Purification.\" Ririsa continues more cheerfully.\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("Ririsa then takes Elias to the home of the leader of The Night Raiders.\n", 40);
    typing("\"Gary, I brought a new friend. She says she's from Morivelle.\" Ririsa says cheerfully.\n", 40);
    typing("A middle-aged man with long hair tied back appears from inside the house and greets Elias warmly.\n", 40);
    typing("\"From Morivelle? Is there a survivor?\" Gary asks.\n");
    typing("\"No. She comes from outside the city. She's here to go home.\" Ririsa answers.\n");
    typing("\"So, a native Morivelle citizen who went outside the city and came home without knowing the state of the city. You must have lived alone and far from Morivelle for a very long time.\" Gary says with a tone full of concern.\n", 40);
    typing("\"Emm... You could say that.\" Elias clarifies.\n", 40);
    typing("\"Ririsa, can you wait outside and give me time to talk with this Morivelle lady\"\n", 40);
    typing("\"Of course Gary. I'll wait outside\" Ririsa says to Elias while stepping out with a bright smile.\n", 40);
    typing("Gary then invites Elias into his house to talk further", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"May I know more about you?\" Gary starts the conversation\n ", 40);
    typing("\"Emm... My name is Elias Viremont. I was born in Morivelle and I grew up here until I was 18.\n", 40);
    typing("\"At that time I got a scholarship to study at Demirgus University.\n", 40);
    typing("\"I left Morivelle for education exactly 5 years ago and everything was normal back then.\"\n", 40);
    typing("\"And 5 years later, or more precisely now you're here to go home but everything suddenly fell apart.\" Gary adds, cutting off Elias's words.\n", 40);
    typing("\"I understand, but do you know what happened here?\" Gary adds.\n", 40);
    typing("\"No. Do you know what happened here?\" Elias asks in return.\n", 40);
    typing("\"No.\" Gary answers with certainty.\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"We came exactly 2 years ago when everything here was already destroyed\"\n", 40);
    typing("\"We are nomadic. When we came to this area, everything seemed to be possessed by Yokai\"\n", 40);
    typing("Note: Yokai are spiritual creatures in Japanese mythology that can possess humans or inanimate objects and make them evil.\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"We managed to purify this area with our special abilities\"\n", 40);
    typing("\"We also built our settlement here, which later became our place of residence\"\n", 40);
    typing("\"The area here is not as contaminated as other places.\"\n", 40);
    typing("\"What still confuses us is why this city became so destroyed and contaminated.\"\n", 40);
    typing("\"We searched to see if anyone was rescued or also living here\"\n", 40);
    typing("\"We also studied the natural situation around here\"\n", 40);
    typing("\"Both ended in nothing and there's nothing that can be explained according to our knowledge\"\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"In Demirgus, I'm also experimenting with something similar,\" Elias begins to share his research.\n", 40);
    typing("\"In Demirgus something that changes natural phenomena is also happening, only not as severe as here.\"\n", 40);
    typing("\"In theory, this is called The Red Tide. A phenomenon where nature changes itself into something more dangerous and destructive.\"\n", 40);
    typing("\"The Red Tide can change everything in nature, including living creatures, into something more dangerous and destructive.\"\n", 40);
    typing("\"This phenomenon can happen suddenly and spread quickly.\"\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"So do you mean nature has a will of its own? That sounds strange,\" Gary says.\n", 40);
    typing("\"This is still just my theory, and because it sounds strange, that's why I'm investigating this Red Tide more deeply,\" Elias continues\n", 40);
    typing("\"So you're actually here to investigate this?\" Gary asks.\n", 40);
    typing("\"Not exactly. My professor asked me to take a vacation so I decided to go home,\" Elias answers\n", 40);
    typing("\"Hmm. Now the question for me is what are you going to do next?\" Gary adds with a question\n", 40);
    typing("\"I originally wanted to go back to Demirgus and ask for help to conduct an investigation to Morivelle,\" Elias answers\n", 40);
    typing("\"However, because the harbor has started to be blocked by those strange creatures, I can't go back.\" Elias adds\n", 40);
    typing("\"Since we're both in a confusing situation, I will help you with your research.\" Gary invites.\n", 40);
    typing("\"If you really want to go back and investigate this all until the truth is revealed, I will be happy to help.\" Gary continues.\n", 40);
    typing("\"How are you going to help me?\" Elias asks.\n", 40);
    typing("\"We can help you clean the harbor area and rebuild it so you can go back,\" Gary answers.\n", 40);
    typing("\"Do you mean the Ariolla Monument area?\" Elias continues with a question.\n", 40);
    typing("\"Yes, whatever that place is called. We need to clean that area and rebuild it so that when you come back here later, you can arrive safely.\" Gary answers optimistically.\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"So... do we have a deal?\" Gary asks while offering his hand to shake.\n", 40);
    typing("\"Alright, I promise you that what happened here I will solve,\" Elias answers while shaking Gary's hand.\n", 40);
    typing("Gary smiles", 40);
    typing("\"Okay, we have a deal. I will inform Ririsa and Darius to accompany you. Maybe you can tell Ririsa directly,\" Gary says firmly.\n", 40);
    typing("Elias smiles, then she leaves Gary's house.\n", 40);
    typing("Outside, Ririsa is already waiting cheerfully\n", 40);
    typing("\"How was your conversation with Gary?\" Ririsa asks cheerfully.\n", 40);
    typing("Elias then tells Ririsa about her conversation with Gary.\n", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("\"Wow... So we're going to clean up Ariolla Monument?\" Ririsa asks cheerfully.\n", 40);
    typing("\"Yes, we will clean up Ariolla Monument so I can go back to Demirgus,\" Elias answers.\n", 40);
    typing("\"Cool! When do we start?\" Ririsa asks cheerfully.\n", 40);
    typing("Tutorial: You will begin city building to clean and rebuild Ariolla Monument. If you successfully rebuild Ariolla Monument, you can continue the story. Try your best to rebuild Ariolla Monument!", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,8);
    return 0;
}

int chap1e(string username){
    system("cls");
    typing("ACT 2 - Rovenila's Secret", 100);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("", 40);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,10);
    return 0;
}

int chap1f(string username){
    system("cls");
    typing("ACT 3 - Rovenila's Secret", 100);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("", 40);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,12);
    return 0;
}

int chap1g(string username){
    system("cls");
    typing("ACT 4 - Rovenila's Secret", 100);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("", 40);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,14);
    return 0;
}

int chap1h(string username){
    system("cls");
    typing("ACT 5 - Rovenila's Secret", 100);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    typing("", 40);

    if (waitOrSkip()) {
        return 0;
    }
    system("cls");

    saveGame(username,1,16);
    return 0;
}

int chap1(int scene, string username) {

    if (scene <= 1) chap1a(username);
    if (scene <= 2) {
        saveGame(username,1, 2);
        bsp(username);
    }
    if (scene <= 3) chap1b(username);
    if (scene <= 4) {
        saveGame(username,1, 4);
        mc(username);
    }
    if (scene <= 5) chap1c(username);
    if (scene <= 6) {
        saveGame(username,1, 6);
        battle1(username);
    }
    if (scene <= 7) chap1d(username);
    if (scene <= 8) {
        saveGame(username,1, 8);
        mainCity(username,1,8);
    }
    membaca(username);
    if (!act1()){
        return 0;
    }
    if (quit == 'y' || quit == 'Y'){
        return 0;
    }
    if (scene <= 9) chap1e(username);
    if (scene <= 10) {
        saveGame(username,1,10);
        daerah[2].unlock = true;
        daerah[3].unlock = true;
        updateBuilding(username);
        mainCity(username,1,10);
    }
    membaca(username);
    if (!act2()){
        return 0;
    }
    if (quit == 'y' || quit == 'Y'){
        return 0;
    }
    if (scene <= 11) chap1f(username);
    if (scene <= 12){
        saveGame(username,1,12);
        mainCity(username,1,12);
    }
    membaca(username);
    if (!act3()){
        return 0;
    }
    if (quit == 'y' || quit == 'Y'){
        return 0;
    }
    if (scene <= 13) chap1g(username);
    if (scene <= 14){
        saveGame(username,1,14);
        daerah[4].unlock = true;
        updateBuilding(username);
        mainCity(username,1,14);
    }
    membaca(username);
    if (!act4()){
        return 0;
    }
    if (quit == 'y' || quit == 'Y'){
        return 0;
    }
    if (scene <= 15) chap1h(username);
    if (scene <= 16){
        saveGame(username,1,16);
        mainCity(username,1,16);
    }
    
    return 0;
}