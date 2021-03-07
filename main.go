package main
import "fmt"
import "os"
import "io/ioutil"
import "strings"
func main() {
	var homedir, _ = os.UserHomeDir()
	configfile := homedir+"/.config/systemgo/config.conf"
	var open, openerr = os.Open(configfile)
	var formatted, _ = ioutil.ReadAll(open)
	if openerr != nil {
		fmt.Println(`a config file has not been created. It's location is ~/.config/systemgo/config.conf. Here is a default to copy and paste into that file: 
Editors vi nano emacs nvim
Fun figlet lolcat cowsay cmatrix nsnake
PackManager pacman apt flatpak snap yum nix
Languages gcc java python g++ dotnet node mysql nasm Rscript groovy go perl ruby rustc ghci ocaml clojure kotlin
WM i3 dwm bspwm
Multimedia blender mpv vlc imagemagick feh nitrogen gimp pinta`)
	}
	// err := json.Unmarshal(formatted, &data)
	lines := strings.Split(string(formatted), "\n")
	pack := make([][]string, len(lines))
	for k:=0; k< len(lines); k++ {
		pack[k] = strings.Split(lines[k], " ")
	}
	for i:=0; i< len(pack); i++ {
		fmt.Println(pack[i][0])
		for j:=1; j<len(pack[i]); j++ {
			if _, err := os.Stat("/usr/bin/" + pack[i][j]); err == nil {
				fmt.Println("[ \033[01;32mYEA\033[0m ] " + pack[i][j] + " exists!" )
			} else if os.IsNotExist(err) {
				fmt.Println("[ \033[01;31mNAY\033[0m ] " + pack[i][j] + " is not installed." )
			} else {
				fmt.Println("this is not supposed to happen. You are likely encountering a bug.")
			}
		}
	}
}

