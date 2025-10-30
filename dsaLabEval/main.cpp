#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
  int sid;
  string songName;
  int duration;//in seconds
  Node *rlink;
  Node *llink;
};

class MusicPlayer {
public:
  Node* addMusic(Node *T, int pos, int sid, string songName, int duration) {
    Node *x = (Node *)malloc(sizeof(Node));
    x->sid = sid;
    x->songName = songName;
    x->duration = duration;

    if (T == NULL) {
      T = x;
      T->llink = NULL;
      T->rlink = NULL;
      return T;
    }
    Node *p = T;
    int i = 0;
    while (i < pos-1 && p->rlink != NULL )  {
      p = p->rlink;
      i++;
    }
    Node* next = p->rlink;
    if (next !=NULL)
    {
      next->llink = x;
    }
    p->rlink = x;
    x->llink = p;
    x->rlink = next;
    return x;
  }
  bool delSong(Node *songNode) {
    if (songNode == NULL) return false;
    Node *prev = songNode->llink;
    Node *next = songNode->rlink;
    free(songNode);
    if(prev != NULL)
      prev->rlink = next;
    if (next != NULL)
      next->llink = prev;
    return true;
  }

  bool playSong(Node *songNode) {
    if (songNode == NULL) return false;
    printf("Now playing :%d %s\n", songNode->sid,songNode->songName.c_str());
    return true;
  }

  bool printIt(Node *T){
    Node* p = T;
    while(p!=NULL)
    {
      printf("%s<=>",p->songName.c_str());
      p = p->rlink;
    }
    return true;
  }


  bool playPrev(Node *songNode) {
    if (songNode == NULL)
      return false;
    playSong(songNode->llink);
    return true;
  }

  bool playNext(Node *songNode) {
    if (songNode == NULL)
      return false;
    playSong(songNode->rlink);
    return true;
  }

  int bells(Node *songNode, int b1, int b2, int b3) {
    for (int i = 1; i <= songNode->duration; i++) {
      if (i% b1 == 0 &&
          i% b2 == 0 &&
          i% b3 == 0) {
                printf("Match at %d\n",i);
                return true;
      }
    }
    printf("No match\n");
        return false;
  }
};

int main() {
    MusicPlayer player;
    Node* T = player.addMusic(NULL, 0, 1,"Hello", 100);
    Node* mellow = player.addMusic(T, 1, 2,"Mello", 120);
    Node* jello = player.addMusic(T, 1, 3,"Jello", 30);
    player.playSong(mellow);
    player.playPrev(mellow);
    player.bells( mellow, 5, 10, 9);
    player.bells( jello, 5, 10, 9);
    player.bells( T, 5, 10, 9);
    player.delSong(mellow);
}
