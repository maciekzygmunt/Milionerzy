#include<iostream>
#include<locale.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>


using namespace std;
int main() {
    setlocale(LC_CTYPE, "Polish");
    srand(time(0));
    int index;
    int licznikDobrychOdpowiedzi = 0;
    int licznikZlychOdpowiedzi = 0;
    string pytania[100];
    char odpowiedzi[100];
    string odpowiedzi_pobrane[100];
    fstream wyniki; //zmienna na wyniki w pliku
    fstream pytania_w_pliku; //zmienna na pytania w pliku
    fstream odpowiedzi_w_pliku; //zmienna na odpowiedzi w pliku
    string nick; //zmienna na nick do wyni�w
    string pytaniapolnapol[100];
    int polnapol = 0;
    int podwojnaodpowiedz = 0;
    int zamianapytania = 0;
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //latwe
    /*
    pytania[] = ":\na. \t b. \nc. \t d. \n";
    odpowiedzi[] = '';
    */
    /*
    pytania[9] = "";
    odpowiedzi[9] = '';
    */

    pytania[1] = "Kt�ry z tych u�amk�w to u�amek niew�a�ciwy?:\na. 3/4\tb. 0,3\nc. 4/3\td. 0,33\n";
    odpowiedzi[1] = 'c';
    pytania[2] = "Twarz i poca�unek to?:\na. morda\tb. ca�us\nc. cmok \td. buziak\n";
    odpowiedzi[2] = 'd';
    pytania[3] = "Do czego s�u�y krawcowej blaszka na palec?:\na. do ochrony palca\t         b. do prucia fastryg\nc. do obrzucania dziurek\t d. do nawlekania igie�\n";
    odpowiedzi[3] = 'd';
    pytania[4] = "Wska� b��d.:\na. wymy�li� co� napr�dce\t b. schodzi� na manowce\nc. nadwer�y� plecy\t         d. podda� co� w w�tpliwo��\n";
    odpowiedzi[4] = 'd';
    pytania[5] = "K��ci� si� z kim�, robi� mu na z�o�liwo�ci to p�j�� z nim:\na. w sukurs\t b. jak w dym\nc. w konkury\t d. na udry\n";
    odpowiedzi[5] = 'd';
    pytania[6] = "Co ma lodowiec?:\na. ga�y\t b. j�zor\nc. gir�\t d. ka�dun\n";
    odpowiedzi[6] = 'b';
    pytania[7] = "Polskie ruskie pierogi nadziewane s�?:\na. bia�� i czerwon� kapust�\t b. bia�a i czerwon� fasol�\nc. bia�ym i czerwonym mi�sem\t d. ziemniakami i serem\n";
    odpowiedzi[7] = 'd';
    pytania[8] = "W jakim mie�cie odbywa�y si� s�ynne spotkania naukowo-literackie zwane obiadami czwartkowymi?:\na. w Gnie�nie\t b. w Pu�awach\nc. w Warszawie\t d. w Krakowie\n";
    odpowiedzi[8] = 'c';
    pytania[9] = "Kto napisa� �Would you know my name if I saw you in heaven�I to �piewa z gitar�?:\na. Soyka\t b. Phil Collins\nc. Eric Clapton\t d. Sting\n";
    odpowiedzi[9] = 'c';
    pytania[10] = "Czego mog�a u�yczy� Dafne po przemianie?:\na. laski wanilii\t b. listka bobkowego\nc. kryszta�u soli\t d. kory cynamonu\n";
    odpowiedzi[10] = 'b';
    pytania[11] = "Na krech�:\na. powo�ywa� si� T.Mazowiecki\t b. skacze temperatura\nc. zje�d�aj� narciarze\t         d. czeka� przys�owiowy Matysek\n";
    odpowiedzi[11] = 'c';
    pytania[12] = "Zagalopowa� si� to posun�� si�:\na. w latach\t b. nieco na koniu\nc. za daleko\t d. o w�os\n";
    odpowiedzi[12] = 'c';
    pytania[13] = "Nie ma �adnych pa�stw o�ciennych:\na. Polska\t b. Portugalia\nc. Serbia\t d. Islandia\n";
    odpowiedzi[13] = 'd';
    pytania[14] = "Kt�ry instrument stroi muzyk?:\na. tamburyn\t b. kocio�\nc. okaryn�\t d. czynele\n";
    odpowiedzi[14] = 'b';
    pytania[15] = "Z gry na jakim instrumencie s�ynie Czes�aw Mozil?:\na. na kornecie\t b. na akordeonie\nc. na djembe\t d. na saksofonie\n";
    odpowiedzi[15] = 'b';
    pytania[16] = "Co ukoi nerwy i zast�pi cytryn�?:\na. melisa lekarska\t b. mi�ta pieprzowa\nc. jask�cze ziele\t d. ziele angielskie \n";
    odpowiedzi[16] = 'a';
    pytania[17] = "Co kroimy w pi�rka?:\na. cebul�\t b. natk� pietruszki\nc. buraki\t d. seler naciowy \n";
    odpowiedzi[17] = 'a';
    pytania[18] = "Jaki kolor ma dodawany do gum do �ucia, pasta do z�b�w, cukru pudru i wielu innych produkt�w dwutlenku tytanu?:\na. zielony\t b. czerwony\nc. czarny\t d. bia�y \n";
    odpowiedzi[18] = 'd';
    pytania[19] = "Wszystkie �mieci rozk�adaj� si� kilkaset lat, ale najd�u�ej:\na. pampers\t         b. plastikowa torebka\nc. �y�ka w�dkarska\t d. aluminiowa puszka \n";
    odpowiedzi[19] = 'c';
    pytania[20] = "Kt�ry z indeks�w reprezentuje Gie�d� Papier�w Warto�ciowych w Warszawie?:\na. DAX\t b. NASDAQ\nc. WIG\t d. Dow Jones \n";
    odpowiedzi[20] = 'c';
    pytania[21] = "Politycy ��cz� w popularna piramidk�:\na. mandaty poselskie\t b. proletariuszy wszystkich kraj�w\nc. palce d�oni\t         d. punkty wyst�pienia \n";
    odpowiedzi[21] = 'c';
    pytania[22] = "Jaka cz�� mowy odpowiada na pytania: kto, co?:\na. przymiotnik\t b. czasownik\nc. rzeczownik\t d. przys��wek \n";
    odpowiedzi[22] = 'c';
    pytania[23] = "Co powstanie z wody, gdy j� zamrozimy?:\na. para\t b. chmura\nc. l�d\t d. mleko \n";
    odpowiedzi[23] = 'c';
    pytania[24] = "Jaka legenda jest zwi�zana z Warszaw�?:\na. o smoku wawelskim \t                 b. o Popielu\nc. o Wandzie, co nie chcia�a Niemca\t d. o syrence \n";
    odpowiedzi[24] = 'd';
    pytania[25] = "Kto ma �eb obdarty?:\na. kto p�no przychodzi  \t b. kto jest kr�tko ostrzy�ony \nc. kto gra w karty \t         d. kto ma nos zadarty \n";
    odpowiedzi[25] = 'c';
    pytania[26] = "Jak si� pisze wyraz (rz/�)(�/u)raw? :\na. �, �   \t b. rz, u  \nc. rz, u  \t d. �, u \n";
    odpowiedzi[26] = 'd';
    pytania[27] = "Co nie jest nazw� stylu p�ywackiego?:\na. rekin \t b. kraul \nc. �abka \t d. delfin \n";
    odpowiedzi[27] = 'a';
    pytania[28] = "Kt�ra z tych ma�p jest najwi�ksza?:\na. orangutan \t b. kapucynka \nc. szympans \t d. goryl \n";
    odpowiedzi[28] = 'd';
    pytania[29] = "Jaki jest numer stra�y po�arnej?:\na. 999 \t b. 997 \nc. 998 \t d. 996 \n";
    odpowiedzi[29] = 'c';
    pytania[30] = "W jakim mie�cie jest Wawel?:\na. we Wroc�awiu \t b. w Warszawie \nc. w Poznaniu \t         d. w Krakowie \n";
    odpowiedzi[30] = 'd';
    pytania[31] = "Gdzie le�y Arktyka?:\na. wok� bieguna po�udniowego \t b. wok� bieguna p�nocnego \nc. na r�wniku \t                 d. na Ksi�ycu \n";
    odpowiedzi[31] = 'b';
    pytania[32] = "Trzy z czterech nazw odnosz� si� do tego samego oceanu. Kt�ra go nie dotyczy?:\na. Atlantyk \t b. Ocean Wielki \nc. Pacyfik \t d. Spokojny \n";
    odpowiedzi[32] = 'a';
    pytania[33] = "Kt�re ze �wi�t dzieli najmniejsza liczba dni od Andrzejek?:\na. Bo�e Narodzenie \t b. Wielkanoc \nc. Zaduszki \t         d. �wi�to Trzech Kr�li \n";
    odpowiedzi[33] = 'a';
    pytania[34] = "Ile rodzonych c�rek mia�a macocha Kopciuszka w ba�ni braci Grimm?:\na. dwie \t b. trzy \nc. cztery \t d. pi�� \n";
    odpowiedzi[34] = 'a';
    pytania[35] = "Jak to dalej sz�o? �Opowiem ci bajk�, jak kot pali� fajk�, a kocica papierosa� :\na. koci�ta za� skr�ta \t b. w fifce, byle dalej nosa \nc. upali�a kawa� nosa \t d. te koty zesz�y z drogi cnoty \n";
    odpowiedzi[35] = 'c';
    pytania[36] = "Czym Chi�czycy tradycyjnie jadaj� potrawy z ry�u?:\na. �y�kami \t b. wyka�aczkami \nc. widelcami \t d. pa�eczkami \n";
    odpowiedzi[36] = 'd';
    pytania[37] = "Ile miesi�cy liczy kwarta�?:\na. 2 \t b. 3 \nc. 4 \t d. 5 \n";
    odpowiedzi[37] = 'b';
    //srednie
    pytania[38] = "Kim z zawodu jest Frank Underwood � g��wny bohater serialu �House of Cards?:\na. kierowc� rajdowym \t b. architektem \nc. politykiem \t         d. pokerzyst� \n";
    odpowiedzi[38] = 'c';
    pytania[39] = "S��e� to antropometryczna miara d�ugo�ci r�wna rozpi�to�ci:\na. pi�t \t          b. ramion \nc. ramion cyrkla \t  d. zainteresowa� \n";
    odpowiedzi[39] = 'b';
    pytania[40] = "Co jest charakterystyczne w umaszczeniu doga niemieckiego zwanego arlekinem?:\na. czarna podpalana sier�� \t  b. r�wno rozmieszczone pr�gi \nc. czarne �aty na bia�ym tle \t  d. jednolity z�oty kolor \n";
    odpowiedzi[40] = 'c';
    pytania[41] = "Dziko ro�nie w Polsce i jest lian�:\na. aktinidia smakowita \t  b. bluszcz pospolity \nc. malina w�a�ciwa \t  d. grab \n";
    odpowiedzi[41] = 'b';
    pytania[42] = "W papieskim b�ogos�awie�stwie �Urbi et Orbi� - urbi znaczy miastu, a orbi?:\na. wsi \t          b. �wiatu \nc. s�o�cu \t  d. obie�y�wiatom \n";
    odpowiedzi[42] = 'b';
    pytania[43] = "S�ynne zwierz� senator za panowania cesarza Kaliguli to:\na. ko� \t          b. w�� \nc. kozio� \t  d. kanarek \n";
    odpowiedzi[43] = 'a';
    pytania[44] = "Kt�ry z p�wysp�w nie ma sta�ych rzek?:\na. P�wysep Skandynawski \t b. P�wysep Jutlandzki \nc. P�wysep Indyjski \t         d. P�wysep Arabski \n";
    odpowiedzi[44] = 'd';
    pytania[45] = "Co ma �apawica?:\na. brak zahamowa� \t         b. �futera�� na kciuk \nc. sta�y potencja� infekcyjny \t d. sk�adany miech \n";
    odpowiedzi[45] = 'b';
    pytania[46] = "Jan Kochanowski po �mierci Zygmunta Augusta by� zwolennikiem i uczestniczy� w elekcji:\na. Augusta III Sasa \t b. Jana III Sobieskiego \nc. Jana II Kazimierza \t d. Henryka Walezego \n";
    odpowiedzi[46] = 'd';
    pytania[47] = "Okulbaczy� to:\na. sprawi� sobie binokle \t b. zaszczepi� drzewko \nc. kontrolowa� okulist�w \t d. osiod�a� wierzchowca \n";
    odpowiedzi[47] = 'd';
    pytania[48] = "Kt�ra z biblijnych postaci nosi przydomek Iskariota?:\na. Moj�esz \t b. Judasz \nc. Noe \t         d. Abel \n";
    odpowiedzi[48] = 'b';
    pytania[49] = "Kt�rych bierek w bierkach jest najwi�cej?:\na. wiose� \t b. bosak�w \nc. tr�jz�b�w \t d. oszczep�w \n";
    odpowiedzi[49] = 'd';
    pytania[50] = "Wszystkie cztery brzmi� tak samo, a jedno wygl�da i brzmi inaczej odwo�uje si� do prawdy. Kt�re?:\na. bana� \t b. komuna� \nc. frazes \t d. truizm \n";
    odpowiedzi[50] = 'd';
    pytania[51] = "Komiksowym 'dzieckiem' rysownika Boba Kane'a jest:\na. Superman \t b. Batman \nc. Spider-Man \t d. Captain Ameryka \n";
    odpowiedzi[51] = 'b';
    pytania[52] = "Likier maraskino produkuje si� z maraski, czyli odmiany:\na. wi�ni \t b. jab�oni \nc. figi \t d. gruszy \n";
    odpowiedzi[52] = 'a';
    pytania[53] = "Kt�ry utw�r Juliusza S�owackiego napisany jest proz�?:\na. �Godznia my�li� \t b. �W Szwajcarii� \nc. �Anhelli� \t         d. �Arabi� \n";
    odpowiedzi[53] = 'c';
    pytania[54] = "Kt�ry ssak si� nie spoci?:\na. owca \t b. ko� \nc. cz�owiek \t d. kr�lik \n";
    odpowiedzi[54] = 'd';
    pytania[55] = "Kogo dotyczy gamofobia?:\na. kandydat�w do pracy \t         b. przysz�ych ma��onk�w \nc. uczni�w przed matur� \t d. graczy na gie�dzie \n";
    odpowiedzi[55] = 'b';
    pytania[56] = "Pad to najd�u�sza rzeka:\na. Hiszpanii \t b. Portugalii \nc. Grecji \t d. W�och \n";
    odpowiedzi[56] = 'd';
    pytania[57] = "Kt�ry smerf na ramieniu wytatuowane serce przebit� strza��?:\na. maruda \t b. osi�ek \nc. wa�niak \t d. ciamajda \n";
    odpowiedzi[57] = 'b';
    pytania[58] = "Co t�usty krem potrafi zostawi� na sk�rze?:\na. koncert \t         b. sztuk� \nc. oper� mydlan� \t d. film \n";
    odpowiedzi[58] = 'd';
    pytania[59] = "Za co przytulaj� hajs snugglersi?:\na. za przytulanie \t b. za lanie \nc. za kas� \t         d. za mas� \n";
    odpowiedzi[59] = 'a';
    pytania[60] = "Kogo uratowa�a Calineczka?:\na. kreta \t b. jask�k� \nc. pingwina \t d. �ab� \n";
    odpowiedzi[60] = 'b';
    pytania[61] = "Ile jest znak�w zodiaku?:\na. 12  \t b. 15 \nc. 16 \t d. 10 \n";
    odpowiedzi[61] = 'a';
    pytania[62] = "Do ilu punkt�w liczy si� set w tenisie sto�owym?:\na. 21  \t b. 25 \nc. 31 \t d. 20 \n";
    odpowiedzi[62] = 'a';
    pytania[63] = "Jakie s� najwy�sze g�ry na �wiecie?:\na. Tatry \t b. Himalaje \nc. Pireneje \t d. Alpy \n";
    odpowiedzi[63] = 'b';
    pytania[64] = "Kt�ry z podanych instrument�w nie nale�y do grupy aerofon�w?:\na. ob�j \t b. tuba \nc. dudy \t d. �ele \n";
    odpowiedzi[64] = 'd';
    pytania[65] = "Wafel pieczony z delikatnego ciasta w specjalnych foremkach to:\na. bajgiel \t b. andrut \nc. bak�awa \t d. beza \n";
    odpowiedzi[65] = 'b';
    pytania[66] = "Kt�re z okre�le� nie oznacza wys�annika?:\na. emisariusz \t b. kurier \nc. pose� \t d. ordyna \n";
    odpowiedzi[66] = 'd';
    pytania[67] = "Tytu�owa wataha z serialu wyre�yserowanego mi�dzy innymi przez Kasi� Adamik to:\na. wilcza rodzina \t b. rosyjscy szpiedzy \nc. stra�nicy graniczni \t d. uchod�cy ze Wschodu \n";
    odpowiedzi[67] = 'c';
    //trunde
    pytania[68] = "Jaki instrument wykorzysta� w�drowny szczuro�ap, kt�ry w XIII wieku mia� wyprowadzi� szkodniki z Hameln?:\na. B�ben \t b. Flet \nc. Puzon \t d. Harf� \n";
    odpowiedzi[68] = 'b';
    pytania[69] = "Konne tramwaje najwcze�niej pojawi�y si� w Warszawie, a elektryczne?:\na. te� w Warszawie \t b. w Bytomiu \nc. w Krakowie \t         d. we Wroc�awiu \n";
    odpowiedzi[69] = 'd';
    pytania[70] = "Wyrazy srebro i pieni�dze brzmi� tak samo, ale tylko:\na. po niemiecku \t b. po rosyjsku \nc. po angielsku \t d. po francusku \n";
    odpowiedzi[70] = 'd';
    pytania[71] = "Przyk�adem transhumancji jest:\na. wyp�dzanie owiec na hale \t b. klonowanie zwierz�t \nc. mit o Minotaurze \t         d. galwanizowanie trupa \n";
    odpowiedzi[71] = 'a';
    pytania[72] = "Symultan� rozgrywa si�:\na. w tenisie ziemnym \t b. w szachach \nc. w zapasach \t         d. w pi�ce no�nej \n";
    odpowiedzi[72] = 'b';
    pytania[73] = "W 1937 r. w ramach pomocy genera�owi Franco baskijsk� stolic� Guernic� prawie do cna zniszczy�y bombardowania:\na. Luftwaffe \t                 b. Wojenno-Wozdusznych Si� \nc. United States Air Forces \t d. Royal Air Force \n";
    odpowiedzi[73] = 'a';
    pytania[74] = "Na szlaku Orlich Gniazd natrafimy na liczne zamki obronne budowane na skalistych, wapiennych wzg�rzach. Jednym z nich jest zamek:\na. w Olsztynie \t b. w Gnie�nie \nc. w Malborku \t d. w �a�cucie \n";
    odpowiedzi[74] = 'a';
    pytania[75] = "�Jako to �wiadczymy, jako Anka zabi�a Maciejowi wieprz i na w�grodzie mu nie da�a pa�� � to wyimek z tekstu:\na. roty wojskowej \t b. roty s�dowej \nc. roty �lubnej \t d. �Roty� Marii Konopnickiej \n";
    odpowiedzi[75] = 'b';
    pytania[76] = "Kto jest mistrzem tego samego or�a, w jakim specjalizowa�a si� mitologiczna Artemida?:\na. Zorro \t b. Legolas \nc. Don Kichot \t d. Longinus Podbipi�ty \n";
    odpowiedzi[76] = 'b';
    pytania[77] = "O ile oczu mniej ma mitologiczny Polifem od mitologicznego olbrzyma Argusa?:\na. o dziewi��dziesi�t dziewi�� \t b. o dziewi��dziesi�t osiem \nc. o jedno \t                 d. o dwoje \n";
    odpowiedzi[77] = 'a';
    pytania[78] = "Sk�d pochodzi� Conan Barbarzy�ca?:\na. z Rivii \t b. z Oz \nc. z Mordoru \t d. z Cimmerii \n";
    odpowiedzi[78] = 'd';
    pytania[79] = "Co wed�ug Leszka Ko�akowskiego jest sklepieniem domu, w kt�rym duch ludzki mieszka?:\na. Rozum \t b. B�g \nc. Mi�o�� \t d. Czas \n";
    odpowiedzi[79] = 'd';
    pytania[80] = "Odra�aj�cy drab z Kabaretu Starszych Pan�w dubelt�wk� we�mie, wyjdzie i...:\na. rach-ciach! \t b. buch, buch! \nc. z rur dw�r \t d. bum w brzuch \n";
    odpowiedzi[80] = 'b';
    pytania[81] = "Co widnieje na fladze Azor�w?:\na. pies \t b. psy \nc. jastrz�b \t d. jastrz�bie\n";
    odpowiedzi[81] = 'c';
    pytania[82] = "R�a�cow� tajemnic� chwalebn� nie jest...:\na. Wniebowzi�cie Matki Boskiej \t b. Zmartwychwstanie Jezusa \nc. �mier� Jezusa na krzy�u \t d. Zes�anie Ducha �wi�tnego\n";
    odpowiedzi[82] = 'c';
    pytania[83] = "Tylko jedno zawiera utarty zwrot. Kt�re?:\na. zebra pasi si� na pasach \t b. droga je�y si� trudno�ci� \nc. licha lisi si� sprytem \t d. j�ki zaj�cz� si� �a�o�nie\n";
    odpowiedzi[83] = 'b';
    pytania[84] = "Choroba �okcia dotycz�ca mi�ni zginaczy, na kt�r� cierpi� denty�ci, ksi�gowi i informatycy, to tak zwany �okie�:\na. golfisty \t b. kierowcy kabrioletu \nc. p�ywaka \t d. skoczka narciarskiego\n";
    odpowiedzi[84] = 'a';
    pytania[85] = "Gdzie w 16 miesi�cy w��kniark� zmieniono w kosmonautk�?:\na. w Chinach \t b. w USA \nc. w ZSRR \t d. w Rumunii\n";
    odpowiedzi[85] = 'c';
    pytania[86] = "Jaki jest kod pocztowy Kluczborku?:\na. 46-203 \t b. 43-370 \nc. 46-201 \t d. 40-200\n";
    odpowiedzi[86] = 'a';
    pytania[87] = "Na akord mo�na:\na. spa� \t b. pracowa� \nc. �piewa� \t d. podr�owa�\n";
    odpowiedzi[87] = 'b';
    pytania[88] = "Co kaftan bezpiecze�stwa ma znacznie d�u�sze ni� zwyk�y kaftan?:\na. prz�d \t b. r�kawy \nc. ty� \t         d. ko�nierz\n";
    odpowiedzi[88] = 'b';
    pytania[89] = "Kto na igrzyskach olimpijskich w Pjongczangu nie m�g� startowa� pod flag� w�asnego kraju?:\na. Kanadyjczycy \t b. Szwedzi \nc. Rosjanie \t         d. Chi�czycy\n";
    odpowiedzi[89] = 'c';
    pytania[90] = "Jak to dalej sz�o? �G�ralu, czy ci nie �al�:\na. �na w�dk� wydawa� szmal� \t         b. �podrzuca� las�w i hal� \nc. �odchodzi� od stron ojczystych� \t d. �religi zostawia� lesistych�\n";
    odpowiedzi[90] = 'c';
    pytania[91] = "Co ��czy rowerowa szprycha?:\na. obr�cz z d�tk� \t b. d�tk� z piast� \nc. piast� z obr�cz� \t d. obr�cz z widelcem\n";
    odpowiedzi[91] = 'c';
    pytania[92] = "Suspens to chwyt stosowany:\na. w zapasach \t                 b. w grze na gitarze \nc. we wspinaczce klasycznej \t d. w filmach\n";
    odpowiedzi[92] = 'd';
    pytania[93] = "Lew zabity przez Ramona Marcedera to:\na. Simba \t b. To�stoj \nc. Trocki \t d. Mufasa\n";
    odpowiedzi[93] = 'c';
    pytania[94] = "Kt�ry z wymienionych nie wyst�pi� w filmie fabularnym przed prezydentur�?:\na. Donald Trump \t b. Ronald Reagan \nc. Lech Kaczy�ski \t d. Valcav Havel\n";
    odpowiedzi[94] = 'd';
    pytania[95] = "Jak nazywa si� ameryka�ska baza wojskowa na Kubie?:\na. Santa Clara \t b. Bayamo \nc. Guantanamo \t d. Matanzas\n";
    odpowiedzi[95] = 'c';
    pytania[96] = "Gdzie produkowany jest od 1835 roku w�oski wermut Cinzano (rodzaj wina)?:\na. w Turynie \t         b. w Wenecji \nc. w Mediolanie \t d. we Florencji\n";
    odpowiedzi[96] = 'a';
    pytania[97] = "Kto by� malarzem kr�la Filipa IV Habsburga?:\na. Marcello Bacciarelli \t b. Jan van Eyck \nc. Diego Vel�zquez \t         d. Jacques-Louis David\n";
    odpowiedzi[97] = 'c';
    pytania[98] = "Ile to jest 1111 razy 1111, je�li 1 razy 1 to 1, a 11 razy 11 to 121?:\na. 12321 \t b. 1 234 321 \nc. 111 111 111 \t d. 123 434 321\n";
    odpowiedzi[98] = 'b';
    pytania[99] = "Symbol waluty euro to stylizowana grecka litera. Kt�ra?:\na. beta \t b. heta \nc. eta \t         d. epsilon\n";
    odpowiedzi[99] = 'd';





    pytaniapolnapol[1] = "Kt�ry z tych u�amk�w to u�amek niew�a�ciwy?:\n-. 3/4\tb. 0,3\nc. 4/3\t-. 0,33\n";
    pytaniapolnapol[2] = "Twarz i poca�unek to?:\n-. morda\tb. ca�us\n-. cmok \td. buziak\n";
    pytaniapolnapol[3] = "Do czego s�u�y krawcowej blaszka na palec?:\na. do ochrony palca\t         -. do prucia fastryg\n-. do obrzucania dziurek\t d. do nawlekania igie�\n";
    pytaniapolnapol[4] = "Wska� b��d.:\n-. wymy�li� co� napr�dce\t -. schodzi� na manowce\nc. nadwer�y� plecy\t         d. podda� co� w w�tpliwo��\n";
    pytaniapolnapol[5] = "K��ci� si� z kim�, robi� mu na z�o�liwo�ci to p�j�� z nim:\n-. w sukurs\t -. jak w dym\nc. w konkury\t d. na udry\n";
    pytaniapolnapol[6] = "Co ma lodowiec?:\n-. ga�y\t b. j�zor\nc. gir�\t -. ka�dun\n";
    pytaniapolnapol[7] = "Polskie ruskie pierogi nadziewane s�?:\n-. bia�� i czerwon� kapust�\t b. bia�a i czerwon� fasol�\n-. bia�ym i czerwonym mi�sem\t d. ziemniakami i serem\n";
    pytaniapolnapol[8] = "W jakim mie�cie odbywa�y si� s�ynne spotkania naukowo-literackie zwane obiadami czwartkowymi?:\na. w Gnie�nie\t -. w Pu�awach\nc. w Warszawie\t -. w Krakowie\n";
    pytaniapolnapol[9] = "Kto napisa� �Would you know my name if I saw you in heaven�I to �piewa z gitar�?:\n-. Soyka\t -. Phil Collins\nc. Eric Clapton\t d. Sting\n";
    pytaniapolnapol[10] = "Czego moga u�yczy� Dafne po przemianie?:\n-. laski wanilii\t b. listka bobkowego\n-. kryszta�u soli\t d. kory cynamonu\n";
    pytaniapolnapol[11] = "Na krech�:\na. powo�ywa� si� T.Mazowiecki\t -. skacze temperatura\nc. zje�d�aj� narciarze\t         -. czeka� przys�owiowy Matysek\n";
    pytaniapolnapol[12] = "Zagalopowa� si� to posun�� si�:\n-. w latach\t -. nieco na koniu\nc. za daleko\t d. o w�os\n";
    pytaniapolnapol[13] = "Nie ma �adnych pa�stw o�ciennych:\n-. Polska\t -. Portugalia\nc. Serbia\t d. Islandia\n";
    pytaniapolnapol[14] = "Kt�ry instrument stroi muzyk?:\n-. tamburyn\t b. kocio�\nc. okaryn�\t -. czynele\n";
    pytaniapolnapol[15] = "Z gry na jakim instrumencie s�ynie Czes�aw Mozil?:\n-. na kornecie\t b. na akordeonie\nc. na djembe\t -. na saksofonie\n";
    pytaniapolnapol[16] = "Co ukoi nerwy i zast�pi cytryn�?:\na. melisa lekarska\t -. mi�ta pieprzowa\nc. jask�cze ziele\t -. ziele angielskie \n";
    pytaniapolnapol[17] = "Co kroimy w pi�rka?:\na. cebul�\t -. natk� pietruszki\nc. buraki\t -. seler naciowy \n";
    pytaniapolnapol[18] = "Jaki kolor ma dodawany do gum do �ucia, pasta do z�b�w, cukru pudru i wielu innych produkt�w dwutlenku tytanu?:\na. zielony\t -. czerwony\n-. czarny\t d. bia�y \n";
    pytaniapolnapol[19] = "Wszystkie �mieci rozk�adaj� si� kilkaset lat, ale najd�u�ej:\n-. pampers\t         b. plastikowa torebka\nc. �y�ka w�dkarska\t -. aluminiowa puszka \n";
    pytaniapolnapol[20] = "Kt�ry z indeks�w reprezentuje Gie�d� Papier�w Warto�ciowych w Warszawie?:\n-. DAX\t b. NASDAQ\nc. WIG\t -. Dow Jones \n";
    pytaniapolnapol[21] = "Politycy ��cz� w popularna piramidk�:\n-. mandaty poselskie\t b. proletariuszy wszystkich kraj�w\nc. palce d�oni\t         -. punkty wyst�pienia \n";
    pytaniapolnapol[22] = "Jaka cz�� mowy odpowiada na pytaniapolnapol: kto, co?:\n-. przymiotnik\t b. czasownik\nc. rzeczownik\t -. przys��wek \n";
    pytaniapolnapol[23] = "Co powstanie z wody, gdy j� zamrozimy?:\na. para\t -. chmura\nc. l�d\t -. mleko \n";
    pytaniapolnapol[24] = "Jaka legenda jest zwi�zana z Warszaw�?:\na. o smoku wawelskim \t                 -. o Popielu\n-. o Wandzie, co nie chcia�a Niemca\t d. o syrence \n";
    pytaniapolnapol[25] = "Kto ma �eb obdarty?:\n-. kto p�no przychodzi  \t b. kto jest kr�tko ostrzy�ony \nc. kto gra w karty \t         -. kto ma nos zadarty \n";
    pytaniapolnapol[26] = "Jak si� pisze wyraz (rz/�)(�/u)raw? :\n-. �, �   \t -. rz, u  \nc. rz, u  \t d. �, u \n";
    pytaniapolnapol[27] = "Co nie jest nazw� stylu p�ywackiego?:\na. rekin \t -. kraul \n-. �abka \t d. delfin \n";
    pytaniapolnapol[28] = "Kt�ra z tych ma�p jest najwi�ksza?:\n-. orangutan \t -. kapucynka \nc. szympans \t d. goryl \n";
    pytaniapolnapol[29] = "Jaki jest numer stra�y po�arnej?:\n-. 999 \t b. 997 \nc. 998 \t -. 996 \n";
    pytaniapolnapol[30] = "W jakim mie�cie jest Wawel?:\n-. we Wroc�awiu \t b. w Warszawie \n-. w Poznaniu \t         d. w Krakowie \n";
    pytaniapolnapol[31] = "Gdzie le�y Arktyka?:\na. wok� bieguna po�udniowego \t b. wok� bieguna p�nocnego \n-. na r�wniku \t                 -. na Ksi�ycu \n";
    pytaniapolnapol[32] = "Trzy z czterech nazw odnosz� si� do tego samego oceanu. Kt�ra go nie dotyczy?:\na. Atlantyk \t -. Ocean Wielki \nc. Pacyfik \t -. Spokojny \n";
    pytaniapolnapol[33] = "Kt�re ze �wi�t dzieli najmniejsza liczba dni od Andrzejek?:\na. Bo�e Narodzenie \t -. Wielkanoc \nc. Zaduszki \t         -. �wi�to Trzech Kr�li \n";
    pytaniapolnapol[34] = "Ile rodzonych c�rek mia�a macocha Kopciuszka w ba�ni braci Grimm?:\na. dwie \t b. trzy \n-. cztery \t -. pi�� \n";
    pytaniapolnapol[35] = "Jak to dalej sz�o? �Opowiem ci bajk�, jak kot pali� fajk�, a kocica papierosa� :\n-. koci�ta za� skr�ta \t b. w fifce, byle dalej nosa \nc. upali�a kawa� nosa \t -. te koty zesz�y z drogi cnoty \n";
    pytaniapolnapol[36] = "Czym Chi�czycy tradycyjnie jadaj� potrawy z ry�u?:\na. �y�kami \t -. wyka�aczkami \n-. widelcami \t d. pa�eczkami \n";
    pytaniapolnapol[37] = "Ile miesi�cy liczy kwarta�?:\n-. 2 \t b. 3 \nc. 4 \t -. 5 \n";
    //srednie
    pytaniapolnapol[38] = "Kim z zawodu jest Frank Underwood � g��wny bohater serialu �House of Cards?:\n-. kierowc� rajdowym \t b. architektem \nc. politykiem \t         -. pokerzyst� \n";
    pytaniapolnapol[39] = "S��e� to antropometryczna miara d�ugo�ci r�wna rozpi�to�ci:\na. pi�t \t          b. ramion \n-. ramion cyrkla \t  -. zainteresowa� \n";
    pytaniapolnapol[40] = "Co jest charakterystyczne w umaszczeniu doga niemieckiego zwanego arlekinem?:\na. czarna podpalana sier�� \t  -. r�wno rozmieszczone pr�gi \nc. czarne �aty na bia�ym tle \t  -. jednolity z�oty kolor \n";
    pytaniapolnapol[41] = "Dziko ro�nie w Polsce i jest lian�:\n-. aktinidia smakowita \t  b. bluszcz pospolity \n-. malina w�a�ciwa \t  d. grab \n";
    pytaniapolnapol[42] = "W papieskim b�ogos�awie�stwie �Urbi et Orbi� - urbi znaczy miastu, a orbi?:\n-. wsi \t          b. �wiatu \nc. s�o�cu \t  -. obie�y�wiatom \n";
    pytaniapolnapol[43] = "S�ynne zwierz� senator za panowania cesarza Kaliguli to:\na. ko� \t          -. w�� \n-. kozio� \t  d. kanarek \n";
    pytaniapolnapol[44] = "Kt�ry z p�wysp�w nie ma sta�ych rzek?:\na. P�wysep Skandynawski \t -. P�wysep Jutlandzki \n-. P�wysep Indyjski \t         d. P�wysep Arabski \n";
    pytaniapolnapol[45] = "Co ma �apawica?:\n-. brak zahamowa� \t         b. �futera�� na kciuk \nc. sta�y potencja� infekcyjny \t -. sk�adany miech \n";
    pytaniapolnapol[46] = "Jan Kochanowski po �mierci Zygmunta Augusta by� zwolennikiem i uczestniczy� w elekcji:\na. Augusta III Sasa \t -. Jana III Sobieskiego \n-. Jana II Kazimierza \t d. Henryka Walezego \n";
    pytaniapolnapol[47] = "Okulbaczy� to:\na. sprawi� sobie binokle \t -. zaszczepi� drzewko \n-. kontrolowa� okulist�w \t d. osiod�a� wierzchowca \n";
    pytaniapolnapol[48] = "Kt�ra z biblijnych postaci nosi przydomek Iskariota?:\n-. Moj�esz \t b. Judasz \nc. Noe \t         -. Abel \n";
    pytaniapolnapol[49] = "Kt�rych bierek w bierkach jest najwi�cej?:\n-. wiose� \t -. bosak�w \nc. tr�jz�b�w \t d. oszczep�w \n";
    pytaniapolnapol[50] = "Wszystkie cztery brzmi� tak samo, a jedno wygl�da i brzmi inaczej odwo�uje si� do prawdy. Kt�re?:\n-. bana� \t -. komuna� \nc. frazes \t d. truizm \n";
    pytaniapolnapol[51] = "Komiksowym 'dzieckiem' rysownika Boba Kane'a jest:\n-. Superman \t b. Batman \nc. Spider-Man \t -. Captain Ameryka \n";
    pytaniapolnapol[52] = "Likier maraskino produkuje si� z maraski, czyli odmiany:\na. wi�ni \t -. jab�oni \nc. figi \t -. gruszy \n";
    pytaniapolnapol[53] = "Kt�ry utw�r Juliusza S�owackiego napisany jest proz�?:\na. �Godznia my�li� \t -. �W Szwajcarii� \nc. �Anhelli� \t         -. �Arabi� \n";
    pytaniapolnapol[54] = "Kt�ry ssak si� nie spoci?:\n-. owca \t b. ko� \n-. cz�owiek \t d. kr�lik \n";
    pytaniapolnapol[55] = "Kogo dotyczy gamofobia?:\n-. kandydat�w do pracy \t         b. przysz�ych ma��onk�w \nc. uczni�w przed matur� \t -. graczy na gie�dzie \n";
    pytaniapolnapol[56] = "Pad to najd�u�sza rzeka:\n-. Hiszpanii \t b. Portugalii \n-. Grecji \t d. W�och \n";
    pytaniapolnapol[57] = "Kt�ry smerf ma na ramieniu wytatuowane serce przebit� strza��?:\n-. maruda \t b. osi�ek \nc. wa�niak \t -. ciamajda \n";
    pytaniapolnapol[58] = "Co t�usty krem potrafi zostawi� na sk�rze?:\n-. koncert \t         -. sztuk� \nc. oper� mydlan� \t d. film \n";
    pytaniapolnapol[59] = "Za co przytulaj� hajs snugglersi?:\na. za przytulanie \t -. za lanie \nc. za kas� \t         -. za mas� \n";
    pytaniapolnapol[60] = "Kogo uratowa�a Calineczka?:\n-. kreta \t b. jask�k� \n-. pingwina \t d. �ab� \n";
    pytaniapolnapol[61] = "Ile jest znak�w zodiaku?:\na. 12  \t -. 15 \n-. 16 \t d. 10 \n";
    pytaniapolnapol[62] = "Do ilu punkt�w liczy si� set w tenisie sto�owym?:\na. 11  \t -. 25 \n-. 31 \t d. 21 \n";
    pytaniapolnapol[63] = "Jakie s� najwy�sze g�ry na �wiecie?:\n-. Tatry \t b. Himalaje \n-. Pireneje \t d. Alpy \n";
    pytaniapolnapol[64] = "Kt�ry z podanych instrument�w nie nale�y do grupy aerofon�w?:\n-. ob�j \t -. tuba \nc. dudy \t d. �ele \n";
    pytaniapolnapol[65] = "Wafel pieczony z delikatnego ciasta w specjalnych foremkach to:\n-. bajgiel \t b. andrut \nc. bak�awa \t -. beza \n";
    pytaniapolnapol[66] = "Kt�re z okre�le� nie oznacza wys�annika?:\na. emisariusz \t -. kurier \n-. pose� \t d. ordyna \n";
    pytaniapolnapol[67] = "Tytu�owa wataha z serialu wyre�yserowanego mi�dzy innymi przez Kasi� Adamik to:\n-. wilcza rodzina \t b. rosyjscy szpiedzy \nc. stra�nicy graniczni \t -. uchod�cy ze Wschodu \n";
    //trunde
    pytaniapolnapol[68] = "Jaki instrument wykorzysta� w�drowny szczuro�ap, kt�ry w XIII wieku mia� wyprowadzi� szkodniki z Hameln?:\n-. B�ben \t b. Flet \nc. Puzon \t -. Harf� \n";
    pytaniapolnapol[69] = "Konne tramwaje najwcze�niej pojawi�y si� w Warszawie, a elektryczne?:\na. te� w Warszawie \t -. w Bytomiu \n-. w Krakowie \t         d. we Wroc�awiu \n";
    pytaniapolnapol[70] = "Wyrazy srebro i pieni�dze brzmi� tak samo, ale tylko:\n-. po niemiecku \t -. po rosyjsku \nc. po angielsku \t d. po francusku \n";
    pytaniapolnapol[71] = "Przyk�adem transhumancji jest:\na. wyp�dzanie owiec na hale \t -. klonowanie zwierz�t \nc. mit o Minotaurze \t         -. galwanizowanie trupa \n";
    pytaniapolnapol[72] = "Symultan� rozgrywa si�:\n-. w tenisie ziemnym \t b. w szachach \nc. w zapasach \t         -. w pi�ce no�nej \n";
    pytaniapolnapol[73] = "W 1937 r. w ramach pomocy genera�owi Franco baskijsk� stolic� Guernic� prawie do cna zniszczy�y bombardowania:\na. Luftwaffe \t                 -. Wojenno-Wozdusznych Si� \n-. United States Air Forces \t d. Royal Air Force \n";
    pytaniapolnapol[74] = "Na szlaku Orlich Gniazd natrafimy na liczne zamki obronne budowane na skalistych, wapiennych wzg�rzach. Jednym z nich jest zamek:\na. w Olsztynie \t b. w Gnie�nie \n-. w Malborku \t -. w �a�cucie \n";
    pytaniapolnapol[75] = "�Jako to �wiadczymy, jako Anka zabi�a Maciejowi wieprz i na w�grodzie mu nie da�a pa�� � to wyimek z tekstu:\n-. roty wojskowej \t b. roty s�dowej \n-. roty �lubnej \t d. �Roty� Marii Konopnickiej \n";
    pytaniapolnapol[76] = "Kto jest mistrzem tego samego or�a, w jakim specjalizowa�a si� mitologiczna Artemida?:\n-. Zorro \t b. Legolas \nc. Don Kichot \t -. Longinus Podbipi�ty \n";
    pytaniapolnapol[77] = "O ile oczu mniej ma mitologiczny Polifem od mitologicznego olbrzyma Argusa?:\na. o dziewi��dziesi�t dziewi�� \t -. o dziewi��dziesi�t osiem \n-. o jedno \t                 d. o dwoje \n";
    pytaniapolnapol[78] = "Sk�d pochodzi� Conan Barbarzy�ca?:\n-. z Rivii \t -. z Oz \nc. z Mordoru \t d. z Cimmerii \n";
    pytaniapolnapol[79] = "Co wed�ug Leszka Ko�akowskiego jest sklepieniem domu, w kt�rym duch ludzki mieszka?:\n-. Rozum \t b. B�g \n-. Mi�o�� \t d. Czas \n";
    pytaniapolnapol[80] = "Odra�aj�cy drab z Kabaretu Starszych Pan�w dubelt�wk� we�mie, wyjdzie i...:\n-. rach-ciach! \t b. buch, buch! \nc. z rur dw�r \t -. bum w brzuch \n";
    pytaniapolnapol[81] = "Co widnieje na fladze Azor�w?:\n-. pies \t b. psy \nc. jastrz�b \t -. jastrz�bie\n";
    pytaniapolnapol[82] = "R�a�cow� tajemnic� chwalebn� nie jest...:\n-. Wniebowzi�cie Matki Boskiej \t b. Zmartwychwstanie Jezusa \nc. �mier� Jezusa na krzy�u \t -. Zes�anie Ducha �wi�tnego\n";
    pytaniapolnapol[83] = "Tylko jedno zawiera utarty zwrot. Kt�re?:\n-. zebra pasi si� na pasach \t b. droga je�y si� trudno�ci� \nc. licha lisi si� sprytem \t -. j�ki zaj�cz� si� �a�o�nie\n";
    pytaniapolnapol[84] = "Choroba �okcia dotycz�ca mi�ni zginaczy, na kt�r� cierpi� denty�ci, ksi�gowi i informatycy, to tak zwany �okie�:\na. golfisty \t -. kierowcy kabrioletu \nc. p�ywaka \t -. skoczka narciarskiego\n";
    pytaniapolnapol[86] = "Jaki jest kod pocztowy Kluczborku?:\na. 46-203 \t -. 43-370 \nc. 46-201 \t -. 40-200\n";
    pytaniapolnapol[87] = "Na akord mo�na:\n-. spa� \t b. pracowa� \n-. �piewa� \t d. podr�owa�\n";
    pytaniapolnapol[88] = "Co kaftan bezpiecze�stwa ma znacznie d�u�sze ni� zwyk�y kaftan?:\n-. prz�d \t b. r�kawy \nc. ty� \t         -. ko�nierz\n";
    pytaniapolnapol[89] = "Kto na igrzyskach olimpijskich w Pjongczangu nie m�g� startowa� pod flag� w�asnego kraju?:\na. Kanadyjczycy \t -. Szwedzi \nc. Rosjanie \t         -. Chi�czycy\n";
    pytaniapolnapol[90] = "Jak to dalej sz�o? �G�ralu, czy ci nie �al�:\n-. �na w�dk� wydawa� szmal� \t         -. �podrzuca� las�w i hal� \nc. �odchodzi� od stron ojczystych� \t d. �religi zostawia� lesistych�\n";
    pytaniapolnapol[91] = "Co ��czy rowerowa szprycha?:\na. obr�cz z d�tk� \t -. d�tk� z piast� \nc. piast� z obr�cz� \t -. obr�cz z widelcem\n";
    pytaniapolnapol[92] = "Suspens to chwyt stosowany:\n-. w zapasach \t                 b. w grze na gitarze \n-. we wspinaczce klasycznej \t d. w filmach\n";
    pytaniapolnapol[93] = "Lew zabity przez Ramona Marcedera to:\na. Simba \t -. To�stoj \nc. Trocki \t -. Mufasa\n";
    pytaniapolnapol[94] = "Kt�ry z wymienionych nie wyst�pi� w filmie fabularnym przed prezydentur�?:\na. Donald Trump \t -. Ronald Reagan \n-. Lech Kaczy�ski \t d. Valcav Havel\n";
    pytaniapolnapol[95] = "Jak nazywa si� ameryka�ska baza wojskowa na Kubie?:\na. Santa Clara \t -. Bayamo \nc. Guantanamo \t -. Matanzas\n";
    pytaniapolnapol[96] = "Gdzie produkowany jest od 1835 roku w�oski wermut Cinzano (rodzaj wina)?:\na. w Turynie \t         -. w Wenecji \nc. w Mediolanie \t -. we Florencji\n";
    pytaniapolnapol[97] = "Kto by� malarzem kr�la Filipa IV Habsburga?:\na. Marcello Bacciarelli \t -. Jan van Eyck \nc. Diego Vel�zquez \t         -. Jacques-Louis David\n";
    pytaniapolnapol[98] = "Ile to jest 1111 razy 1111, je�li 1 razy 1 to 1, a 11 razy 11 to 121?:\n-. 12321 \t b. 1 234 321 \nc. 111 111 111 \t -. 123 434 321\n";
    pytaniapolnapol[99] = "Symbol waluty euro to stylizowana grecka litera. Kt�ra?:\na. beta \t -. heta \n-. eta \t         d. epsilon\n";






    /* pytania_w_pliku.open("pytania.txt", ios::in);
     for (int i = 1; i <= 99; i++)
     {
         getline(pytania_w_pliku, pytania[i]);
     }
     pytania_w_pliku.close();

     odpowiedzi_w_pliku.open("odpowiedzi.txt", ios::in);
     for (int a = 1; a <= 99; a++)
     {
         getline(odpowiedzi_w_pliku, odpowiedzi_pobrane[a]);
     }
     odpowiedzi_w_pliku.close();

     string odpowiedzi_string;
     for (int i = 0; i < 100; i++)
     {
         odpowiedzi_string += odpowiedzi_pobrane[i]; //zamienia tablic� string�w na jednego stringa
     }
     strcpy_s(odpowiedzi, odpowiedzi_string.c_str()); //zamienia stringa na tablic� char�w
     */

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "| $$$$$$$$$$ $$ $$   $$ $$$$$$$$ $$$$    $$ $$$$$$ $$$$$$$  $$$$$$ $$   $$ |\n";
    cout << "| $$$ $$ $$$ $$ $$   $$ $$    $$ $$ $$   $$ $$     $$   $$      $$ $$   $$ |\n";
    cout << "| $$  $$  $$ $$ $$   $$ $$    $$ $$  $$  $$ $$$$   $$$$$$$     $$  $$   $$ |\n";
    cout << "| $$  $$  $$ $$ $$   $$ $$    $$ $$   $$ $$ $$$$   $$$$       $$   $$$$$$$ |\n";
    cout << "| $$  $$  $$ $$ $$   $$ $$    $$ $$    $$$$ $$     $$ $$     $$      $$    |\n";
    cout << "| $$  $$  $$ $$ $$$$ $$ $$$$$$$$ $$     $$$ $$$$$$ $$  $$$  $$$$$$   $$    |\n";
    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
MENU: cout << "Witaj w MILIONERACH!\n 1. Klasyczny tryb gry milionerzy\n 2. Tryb z dowoln� ilosci� pytan\n 3. Zasady \n 4. Wyniki\n";
    char a;   
wybor: 
    cout << "Wybierz opcje z menu\n";
    cin >> a;

        switch (a) {
        case '1':
            wyniki.open("wyniki.txt", ios::out | ios::app); //otwarcie pliku tekstowego z wynikami
            cout << "Prosz� poda� nick: ";
            cin >> nick;
            system("cls");
            //pierwsze pytanie
        ponowne_losowanie_pierwszego:  index = rand() % 37 + 1;
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "Pytanie 1:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z� <- |\n";
            cout << " =====================\n";
            char odp;
        powrot_do_pierwszego:  
            cin >> odp;
            odp = char(tolower(odp));

            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 500z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == '0') {
                system("cls");
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 0 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 0 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_pierwszego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_pierwszego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_pierwszego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_pierwszym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_pierwszego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 1:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda: 500z�!\n";
                else
                {
                    goto porazka_w_pierwszym;
                }
            }
            else {
            porazka_w_pierwszym:  
                cout << "B��dna odpowied�. Wygrywasz 0 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 0 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //drugie pytanie
        ponowne_losowanie_drugiego:  index = rand() % 37 + 1;
            cout << "Pytanie 2:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z� <- |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_drugiego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda gwarantowana: 1000z�.\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 500 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 500 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_drugiego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_drugiego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_drugiego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_drugim;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_drugiego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 2:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda: 1000z�!\n";
                else
                {
                    goto porazka_w_drugim;
                }
            }
            else {
            porazka_w_drugim: cout << "B��dna odpowied�. Wygrywasz 0 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 0 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //trzecie pytanie
        ponowne_losowanie_trzeciego:  index = rand() % 30 + 38;
            cout << "Pytanie 3:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z� <- |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";;
        powrot_do_trzeciego: cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 2 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 1 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 1 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_trzeciego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_trzeciego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_trzeciego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_trzecim;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_trzeciego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 3:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda: 2000z�!\n";
                else
                {
                    goto porazka_w_trzecim;
                }
            }
            else {
            porazka_w_trzecim:  cout << "B��dna odpowied�. Wygrywasz gwarantowane od drugiego pytania 1 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl;
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //czwarte pytanie
        ponowne_losowanie_czwartego:  index = rand() % 30 + 38;
            cout << "Pytanie 4:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z� <- |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_czwartego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 5000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 2000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 2 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_czwartego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \n Nowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_czwartego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_czwartego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_czwartym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_czwartego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 4:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda: 5 000z�!\n";
                else
                {
                    goto porazka_w_czwartym;
                }
            }
            else {
            porazka_w_czwartym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od drugiego pytania 1 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //piate pytanie
        ponowne_losowanie_piatego:  index = rand() % 30 + 38;
            cout << "Pytanie 5:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z� <- |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_piatego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 10 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 5 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 5 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_piatego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \n Nowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_piatego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_piatego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_piatym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_piatego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 5:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda: 10 000z�!\n";
                else
                {
                    goto porazka_w_piatym;
                }
            }
            else {
            porazka_w_piatym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od drugiego pytania 1 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //szoste pytanie
        ponowne_losowanie_szostego:  index = rand() % 30 + 38;
            cout << "Pytanie 6:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z� <- |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_szostego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 20 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 10 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 10 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_szostego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_szostego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_szostego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_szostym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_szostego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 6:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda: 20 000z�!\n";
                else
                {
                    goto porazka_w_szostym;
                }
            }
            else {
            porazka_w_szostym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od drugiego pytania 1 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //siodme pytanie
        ponowne_losowanie_siodmego:  index = rand() % 30 + 38;
            cout << "Pytanie 7:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z� <- |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_siodmego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 40 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 20 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 20 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_siodmego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania!\n Nowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_siodmego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_siodmego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_siodmym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_siodmego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 7:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda gwarantowana: 40 000z�!\n";
                else
                {
                    goto porazka_w_siodmym;
                }
            }
            else {
            porazka_w_siodmym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od drugiego pytania 1 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 1 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //osme pytanie
        ponowne_losowanie_osmego:   index = rand() % 32 + 68;
            cout << "Pytanie 8:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z� <- |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_osmego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 75 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 40 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 40 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_osmego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_osmego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_osmego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_osmym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_osmego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 8:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda : 75 000z�!\n";
                else
                {
                    goto porazka_w_osmym;
                }
            }
            else {
            porazka_w_osmym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od si�dmego pytania 40 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //dziewiate pytanie
        ponowne_losowanie_dziewiatego: index = rand() % 32 + 68;
            cout << "Pytanie 9:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z� <- |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_dziewiatego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 125 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 75 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 75 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_dziewiatego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_dziewiatego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_dziewiatego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_dziewiatym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_dziewiatego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 9:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda : 125 000z�!\n";
                else
                {
                    goto porazka_w_dziewiatym;
                }
            }
            else {
            porazka_w_dziewiatym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od si�dmego pytania 40 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //dziesiate pytanie
        ponowne_losowanie_dziesiatego:  index = rand() % 32 + 68;
            cout << "Pytanie 10:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z� <- |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_dziesiatego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 250 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 125 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 125 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_dziesiatego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_dziesiatego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_dziesiatego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_dziesiatym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_dziesiatego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 10:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda : 250 000z�!\n";
                else
                {
                    goto porazka_w_dziesiatym;
                }
            }
            else {
            porazka_w_dziesiatym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od si�dmego pytania 40 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //jedenaste pytanie
        ponowne_losowanie_jedynastego:  index = rand() % 32 + 68;
            cout << "Pytanie 11:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z�    |\n";
            cout << "| 11:   500.000 z� <- |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_jedynastego:   cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "Dobrze! Obecna nagroda: 500 000z�\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 250 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 250 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_jedynastego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_jedynastego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_jedynastego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "To poprawna odpowied�!\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "To poprawna odpowied�!\n";
                    }
                    else
                    {
                        goto porazka_w_jedynastym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_jedynastego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 11:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) cout << "Poprawna odpowied�! Obecna nagroda : 500 000z�!\n";
                else
                {
                    goto porazka_w_jedynastym;
                }
            }
            else {
            porazka_w_jedynastym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od si�dmego pytania 40 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            //dwunaste pytanie
        ponowne_losowanie_dwunastego: index = rand() % 32 + 68;
            cout << "Pytanie 12:\n" << pytania[index];
            cout << " =====================\n";
            cout << "| 12: 1.000.000 z� <- |\n";
            cout << "| 11:   500.000 z�    |\n";
            cout << "| 10:   250.000 z�    |\n";
            cout << "|  9:   100.000 z�    |\n";
            cout << "|  8:    75.000 z�    |\n";
            cout << "|  7:   *40.000 z�    |\n";
            cout << "|  6:    20.000 z�    |\n";
            cout << "|  5:    10.000 z�    |\n";
            cout << "|  4:     5.000 z�    |\n";
            cout << "|  3:     2.000 z�    |\n";
            cout << "|  2:    *1.000 z�    |\n";
            cout << "|  1:       500 z�    |\n";
            cout << " =====================\n";
        powrot_do_dwunastego:  cin >> odp;
            odp = char(tolower(odp));
            if (odp == odpowiedzi[index]) {
                system("cls");
                cout << "GRATULACJE!!!\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                licznikDobrychOdpowiedzi++;
            }
            else if (odp == 0) {
                cout << "Zdecydowales sie na zabranie pieniedzy i wyjscie z gry. Gratulacje! Wygrywasz 500 000 z�!";
                wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                wyniki << "Wygrana kwota: 500 000 z�" << endl;
                wyniki << "-------------------" << endl;
                wyniki.close();
                break;
            }
            else if (odp == '7')
            {
                if (zamianapytania == 1)
                {
                    cout << "Nie posiadasz ju� zamiany pytania. Prosz� poda� odpowied�:";
                    goto powrot_do_dwunastego;
                }
                system("cls");
                cout << "Wybrano zamiane pytania! \nNowe pytanie: \n";
                zamianapytania++;
                goto ponowne_losowanie_dwunastego;
            }
            else if (odp == '8')
            {
                if (podwojnaodpowiedz == 1)
                {
                    cout << "Nie posiadasz ju� podw�jnej odpowiedzi. Prosz� poda� odpowied�:";
                    goto powrot_do_dwunastego;
                }
                podwojnaodpowiedz++;
                cout << "Wybrano podw�jn� odpowied�! \nProsz� poda� odpowied�(masz jeszcze dwie szanse):";
                cin >> odp;
                if (odp == odpowiedzi[index])
                {
                    system("cls");
                    cout << "GRATULACJE!!!\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                }
                else
                {
                    cout << "Niestety, to nie jest poprawna odpowied�.\nProsz� poda� odpowied�(masz jeszcze jedn� szanse):";
                    cin >> odp;
                    if (odp == odpowiedzi[index])
                    {
                        system("cls");
                        cout << "GRATULACJE!!!\n";
                        cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                        cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                    }
                    else
                    {
                        goto porazka_w_dwunastym;
                    }
                }
            }
            else if (odp == '9')
            {
                if (polnapol == 1)
                {
                    cout << "Nie posiadasz ju� p� na p�. Prosz� poda� odpowied�:";
                    goto powrot_do_dwunastego;
                }
                polnapol++;
                system("cls");
                cout << "Wybrano p� na p�! Wykluczam dwie b��dne odpowiedzi:\n";
                cout << "Pytanie 12:\n" << pytaniapolnapol[index];
                cin >> odp;
                if (odp == odpowiedzi[index]) {
                    cout << "GRATULACJE!!!\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$  $$    $$\n";
                    cout << " $$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$  $$$$$$$$\n";
                }
                else
                {
                    goto porazka_w_dwunastym;
                }
            }
            else {
            porazka_w_dwunastym: cout << "B��dna odpowied�. Wygrywasz gwarantowane od si�dmego pytania 40 000 z�! KONIEC GRY!";
                licznikZlychOdpowiedzi++;
                if (licznikZlychOdpowiedzi == 1) {
                    wyniki << "Gracz:" << nick << endl; //wyslanie wynikow do pliku tekstowego
                    wyniki << "Ilo�� prawid�owych odpowiedzi: " << licznikDobrychOdpowiedzi << endl;
                    wyniki << "Wygrana kwota: 40 000 z�" << endl;
                    wyniki << "-------------------" << endl;
                    wyniki.close();
                    break;
                }
            }
            break;
        case '2':
            cout << "Ile chcesz mie� pyta�?:";
            int iloscPytan;
            cin >> iloscPytan;
            for (int i = 0; i < iloscPytan; i++) {
                index = rand() % 99 + 1;
                cout << pytania[index];
                char odp;
                cin >> odp;
                if (odp == odpowiedzi[index]) {
                    system("cls");
                    cout << "Dobrze!\n";
                    licznikDobrychOdpowiedzi++;
                    if (licznikDobrychOdpowiedzi == iloscPytan) {
                        system("cls");
                        cout << "Koniec pytan. KONIEC GRY!";
                        break;
                    }
                }
                else {
                    licznikZlychOdpowiedzi++;
                    system("cls");
                    cout << "B��dna odpowied�. To twoja " << licznikZlychOdpowiedzi << " z�a odpowied�\n";

                    if (licznikZlychOdpowiedzi == 3) {
                        system("cls");
                        cout << "KONIEC GRY! Pope�ni�e� 3 b��dy.";
                        break;
                    }
                }
            }
            break;
        case '3': //wy�wietlenie zasad
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

            {
                system("cls");
                cout << "===============================================================\n";
                cout << "INSTRUKCJA:\nDo wyboru masz dwa tryby gry:\n1) Klasyczni milionerzy \n2) Losowe pytania" << endl;
                cout << "W trybie klasycznym, rozgrywka wyglada jak lekko zmodyfikowana gra w milioner�w.\nMamy 12 pyta�, 3 ko�a ratunkowe, kwoty gwaranowane oraz koniec gry w razie b��dnej opdowiedzi.\nW ka�dej chwili mo�na wyj�� z gry i zabra� pieni�dze, wpisuj�c 0 zamiast literki z odpowiedzi�.\nJe�li chcesz u�y� k� ratunkowych, wpisz 7/8/9, aby u�y� odpowiednio-zamiany pytania/podw�jna odpowied�/p� na p�. \nW tym trybie wyniki s� zapisywane i mo�na je potem odczyta�" << endl;
                cout << "W trybie losowym, to u�ytkownik decyduje na ile pyta� chce odpowiedzie�, a nast�pnie ma 3 �ycia. W tym trybie nie ma k� ratunkowych ani nagr�d.\nW tym trybie wyniki nie s� zapisywane." << endl;
                cout << "Aby sprawdzi� wyniki z trybu klasycznego, wpisz w menu gry 4.\n";
                cout << "==============================================================\n";
                goto MENU;
                break;
            }
        case '4': //wy�wietlenie wynik�w
        {
            cout << "WYNIKI:" << endl;
            wyniki.open("wyniki.txt", ios::in);
            if (wyniki.good() == false) {
                cout << "Taki plik nie istnieje! Zagraj w trybie klasycznym minimum raz, aby mie� wyniki!";
                goto MENU;
            }
            else {
                string linia;
                int nr_linii = 1;
                while (getline(wyniki, linia))
                {
                    cout << linia << endl;
                }
                wyniki.close();
                goto MENU;
                break;
            }

        }
        default:
            cout << "Znak spoza zakresu\n";
            goto wybor;
        }

}
