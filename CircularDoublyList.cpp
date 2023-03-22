#include <iostream>
#include <fstream>
#include "Node.h"
#include "CircularDoublyList.h"
#include "PLayList.h"
#include "User.h"
#include "Artist.h"
#include "Album.h"
#include "MusicalGenre.h"
#include "Song.h"

int CircularDoublyList::Length()
{
    int cont = 0;

    DoublyPointerNode aux = head->NextNode;
    if (IsEmpty())
    {
        return cont;
    }
    else
    {
        cont = cont + 1;
        while (aux != head)
        {
            aux = aux->NextNode;
            cont++;
        }
        return cont;
    }
};

void CircularDoublyList::Add(Object* obj)
{
    if (IsEmpty()) {
        head = new DoublyNode(obj);
        head->PrevNode = head;
        head->NextNode = head;
    }
    else
    {
        DoublyPointerNode newNode = new DoublyNode(obj);
        newNode->NextNode = head;
        newNode->PrevNode = head->PrevNode;//3
        head->PrevNode->NextNode = newNode;//4
        newNode->NextNode->PrevNode = newNode;
        head = newNode;
    }

};

void CircularDoublyList::DisplayString()
{
   
    if (IsEmpty()) {
        cout << "Lista esta vacia\n";
    }
    else
    {
        DoublyPointerNode aux = head;
        cout << "Id" << " " << "Nombre" << "\n" << endl;

        do {
            cout << aux->value->getId() << " " << aux->value->getName() << "\n" << endl;
            aux = aux->NextNode;
        } while (aux != head);
    }
};

void CircularDoublyList::DisplayElementById(int id)
{

    if (IsEmpty()) {
        cout << "Lista esta vacia\n";
    }
    else
    {
        DoublyPointerNode aux = head;

        do {
            if (aux->value->getId() == id) {

                cout << "El record buscado es -> "  << aux->value->getId() << " " << aux->value->getName() << "\n" << endl;
                return;
            }
            aux = aux->NextNode;
        } while (aux != head);

        cout << "El record no se encontro con el id proveeido" << endl;
    }
};

void CircularDoublyList::DisplayElementByFieldTypeId(int id, string type)
{

    if (IsEmpty()) {
        cout << "Lista esta vacia\n";
    }
    else
    {
        DoublyPointerNode aux = head;

        do {
            if ( type == "userId") {
                PlayList* p = static_cast<PlayList*>(aux->value);
                if (p->getUserId() == id)
                {
                    cout << "El Propietario buscado es -> " << p->getId() << " " << p->getName() << "\n" << endl;
                }
            }
            else if (type == "album") {
                Album* p = static_cast<Album*>(aux->value);
                if (p->getArtistId() == id)
                {
                    cout << "El album buscado es -> " << p->getId() << " " << p->getName() << "\n" << endl;
                }
            }
            else if (type == "artist") {
                Song* s = static_cast<Song*>(aux->value);
                if (s->getArtistId() == id)
                {
                    cout << "La Cancion es -> " << s->getId() << " " << s->getName() << "\n" << endl;
                }
            }
            aux = aux->NextNode;
        } while (aux != head);

    }
};

int CircularDoublyList::GetElementIndexById( int id) //3-4-5    cont=0 1 2 3
{

    int index = -1;
    if (IsEmpty()) {
        return index;
    }
    else
    {
        DoublyPointerNode aux = head;
        index = 0;
            do
            {
                if (aux->value->getId() == id ) {
                    return index;
                }
                else {
                    index++;
                }
                aux = aux->NextNode;
            } while (aux != head);

            return -1;
    }
};

Object* CircularDoublyList::GetElementByKeyId(int id, string type) {
   
    Object* element = NULL;
    if (!IsEmpty()) {
        DoublyPointerNode aux = head;

        do {
            if (type == "user")
            {
                User* user = static_cast<User*>(aux->value);
                if (aux->value->getId() == id) {

                    return user;
                }
            }
            else if (type == "playList")
            {
                PlayList* playList = static_cast<PlayList*>(aux->value);
                if (playList->getUserId() == id) {

                    return playList;
                }
            }
            else if (type == "playListSearchReport")
            {
                PlayList* playList = static_cast<PlayList*>(aux->value);
                if (playList->getId() == id) {

                    return playList;
                }
            }
            else if (type == "artist")
            {
                Artist* artist = static_cast<Artist*>(aux->value);
                if (artist->getMusicalGenreId() == id) {

                    return artist;
                }

            }
            else if (type == "album")
            {
                Album* album = static_cast<Album*>(aux->value);
                if (album->getArtistId() == id) {

                    return album;
                }
            }
            else if (type == "musicalGenre")
            {
                MusicalGenre* musicalGenre = static_cast<MusicalGenre*>(aux->value);
                if (musicalGenre->getId() == id) {

                    return musicalGenre;
                }
            }
            else if (type == "song")
            {
                Song* song = static_cast<Song*>(aux->value);
                if (song->getPlayListId() == id) {

                    return song;
                }
            }
            else if (type == "songAlbum")
            {
                Song* song = static_cast<Song*>(aux->value);
                if (song->getAlbumId() == id) {

                    return song;
                }
            }
            else if (type == "songArtist")
            {
                Song* song = static_cast<Song*>(aux->value);
                if (song->getArtistId() == id) {

                    return song;
                }
            }
            else if (type == "songMusicalGenre")
            {
                Song* song = static_cast<Song*>(aux->value);
                if (song->getMusicGenreId() == id) {

                    return song;
                }
            }
            
            aux = aux->NextNode;
        } while (aux != head);
    }
    return element;
}

Object* CircularDoublyList::GetElementByKeyIdPlayer(int id, int songId) {

    Object* element = NULL;
    if (!IsEmpty()) {
        DoublyPointerNode aux = head;

        do {
            Song* song = static_cast<Song*>(aux->value);
            if (song->getPlayListId() == id && song->getId() == songId) {

                return song;
            }

            aux = aux->NextNode;
        } while (aux != head);
    }
    return element;
}


void CircularDoublyList::SetElementValueById(int id, string name) {

    if (!IsEmpty()) {
        DoublyPointerNode aux = head;

        do {
        
            if (aux->value->getId() == id) {
                aux->value->setName(name);
            }
            
            aux = aux->NextNode;
        } while (aux != head);
    }
}

void CircularDoublyList::RemoveElement()
{
    if (IsEmpty())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (head->NextNode == head)
        {
            DoublyPointerNode temp = head;
            head = NULL;
            delete temp;
        }
        else
        {
            DoublyPointerNode aux = head->PrevNode;//1
            DoublyPointerNode temp = head;//2
            aux->NextNode = head->NextNode;//3
            head = head->NextNode; //4
            head->PrevNode = aux;//5
            delete temp;//6
        }
    }
}

void CircularDoublyList::RemoveElementAtIndex(int index)
{
    if (IsEmpty()) {
        cout << "Lista vacia" << endl;
    }
    else
    {
        if ((index == 0))

        {
            RemoveElement();

        }

        else
        {
            if (index > Length() || (index <= 0))
            {
                cout << "Error en posicion" << endl;
            }

            else
            {
                int cont = 2;
                DoublyPointerNode aux = head;
                while (cont < index)
                {
                    aux = aux->NextNode;
                    cont++;
                }
                DoublyPointerNode temp = aux->NextNode;
                aux->NextNode = aux->NextNode->NextNode;
                aux->NextNode->PrevNode = aux;
                delete temp;
            }
        }
    }
}

bool CircularDoublyList::RemoveFront() {
    
    if (head != NULL) {
        DoublyPointerNode aux = head;
        if (Length() == 1)
        {
            head = NULL;
        }
        else
        {
            DoublyPointerNode back = head->PrevNode;
            back->NextNode = head->NextNode;
            head->NextNode->PrevNode = back;
            head = head->NextNode;
        }
        delete aux;
        return true;
    }
    else
    {
        return false;
    }
}

bool CircularDoublyList::RemoveRear() {
    
    if (head != NULL) {
        if (Length() == 1)
        {
            delete head;
            head = NULL;
        }
        else
        {
            DoublyPointerNode temp = GetPosition(Length() - 1);
            DoublyPointerNode ultimo = this->head->PrevNode;
            temp->NextNode = head;
            head->PrevNode = temp;
            delete ultimo;
        }
        return true;
    }
    else
        return false;
}

bool CircularDoublyList::RemoveAtIndex(int pos)
{
    if (head == NULL)
        return false;
    else
        if ((pos >= 1) && (pos <= Length()))
            if (pos == 1)
                return RemoveFront();
            else
                if (pos == Length())
                    return RemoveRear();
                else
                {
                    DoublyPointerNode back = GetPosition(pos - 1);
                    DoublyPointerNode found = GetPosition(pos);
                    back->NextNode = found->NextNode;
                    found->NextNode->PrevNode = back ;
                    delete found;
                    return true;
                }
        else
            return false;
}

DoublyPointerNode CircularDoublyList::GetPosition(int index)
{
    if (index <= Length())
    {
        if (index == 1)
            return head;
        else
            if (index == Length())
                return head->PrevNode;
            else
            {
                int cont = 1;
                DoublyPointerNode aux = head;
                while (cont != index)
                {
                    aux = aux->NextNode;
                    cont++;
                }
                return aux;
            } 
    } 
    return NULL;
}
