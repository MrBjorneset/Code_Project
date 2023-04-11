# Feedback project24

Innleveringen inneholder `.idea` og CMake/bygg-mappen. 
Disse ønsker vi ikke å dele via VCS da de tar masse plass og vi må uansett slette dem når prosjektet skal bygges på en annen PC. Disse genereres av byggsystemet for plattformen/PCen det bygges på. 

## README

Jobb litt med formateringen og luk bort skrivefeil. 
Merk at du bruker "top-level headline" for alle headings.

Et screenshot hadde vært fint.

## CMake

```cmake
project(threepp_vcpkg_test)

add_executable(test main.cpp)
target_link_libraries(test PRIVATE threepp::threepp imgui::imgui)
```
Endre navnene på prosjektet ("threepp_vcpkg_test") og applikasjonsfilen din ("test").

Om du ikke bruker `imgui` så fjern alle referanser til det i prosjektet.

Bruk liten forbokstav på `Include` folderen. Ellers så ønsker vi å se noe slikt som:

```
data/
include/
  myfile.hpp
src/                 # src folder if not header-only
  myfile.cpp
  CMakeLists.txt
tests/
  CMakeLists.txt
  mytest.cpp
main.cpp       
CMakeLists.txt
README.md
.gitignore
vcpkg.json
vcpkg-configuraion.json
```

Dette er ingen fasit, men en god pekepinn.

---

Ellers så bruker du en relativt gammel versjon av threepp. Oppdater helst fra
`c546ddf3de9b2a0f2a15d58cba14f18134bc1a3a` til `009f337794acefcc548e37f53a9fd16d29a5cfc4` i `vcpkg-configuration.json`.


## Kode

Du velger å splitte deklerasjon og implementasjon internt i headerene. 
Hva med å flytte implementasjonen inn i `.cpp` filer?

Få inn newline mellom ulike funskjoner. Koden ser uoversiktlig ut.

Kjør formatering på koden. `Code->Reformat code`.

Flere steder er det brukt flere `if` setninger etter hverandre, som skulle ha vært `if-else` setninger. 
Vi ønsker ikke å evaluere unødvendige kodestier.

### main

Liten og nett applikasjonsinngang. Det er bra.

```cpp
game.init();
```

Denne funksjonen blokkerer. Det er uventet for en funksjon med det navnet.


### PingPongGame

Klassen `Game` er tett koplet mot visuliseringen. Du har en jobb med å bryte denne koplingen.
Hvordan skal du få testet denne klassen? Hva om du ønsker å bytte rammeverk for visualisering? 

```cpp
auto &ScoreBoard = ...
```
Ikke bruk stor forbokstav på variabelnavn. Unntaket er abbrivations.

Medlemsfunksjonen `Game::update` er stor. Se om du kan delegere noe arbeid ut i andre funksjoner.
Den returnerer også en verdi (alltid 0) som ikke blir brukt.

`std::chrono::milliseconds (16);`<-- død kode


### PingPongScene

Flytt feltene dine over metoder definert med samme visibility.


### Annet

Mangler tester og Continuous integration (CI). Få inn oppsett for dette før enn siden.
Eksempler finnes [her](https://github.com/AIS1002-OOP-V23). CI kan mer eller mindre kopieres fra
[threepp](https://github.com/markaren/threepp/blob/master/.github/workflows/config.yml).
Med denne på plass vil koden bygges og testes i skyen når kode blir pushet til GitHub. Dette gjør det mulig å sjekke
at koden fungerer på et rent system og på andre plattformer enn man selv sitter på (C++ fungerer ikke uten videre på
flere platformer på samme måte som f.eks JavaScript, Python eller Java).
Prosjektet må dog restruktureres for å kunne skrive meningsfulle tester på grunn av den tette koplingen mot visualiseringslaget.

Lykke til videre!

---

Disclaimer: Denne tilbakemeldingen er ikke nødvendigvis fullstendig og kan ha feil eller mangler.
