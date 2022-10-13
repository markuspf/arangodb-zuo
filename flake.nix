{
  inputs = {
    nixpkgs = { url = "github:nixos/nixpkgs/nixos-22.05"; };
    flake-utils = { url = "github:numtide/flake-utils"; };
  };
  outputs = { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
        arangodb-zuo = (with pkgs;
          stdenv.mkDerivation {
            meta = { homepage = ""; };
            pname = "arangodb-zuo";
            version = "git";
            src = ./.;
            nativeBuildInputs = [ clang cmake ];
            buildPhase = "make -j $NIX_BUILD_CORES";
            installPhase = ''
              make install
            '';
          });
      in rec {
        devShell = pkgs.mkShell { buildInputs = [ arangodb-zuo ]; };
        packages.default = arangodb-zuo;
      });
}

