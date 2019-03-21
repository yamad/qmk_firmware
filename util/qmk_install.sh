#!/bin/sh
# Pick the correct install script based on the current OS

util_dir=$(dirname "$0")

case $(uname) in
	Darwin)
		exec "${util_dir}/macos_install.sh"
	;;
	Linux)
		exec "${util_dir}/linux_install.sh"
	;;
	MSYS_NT*|MINGW64_NT*|MINGW32_NT*)
		exec "${util_dir}/msys2_install.sh"
	;;
  *)
    echo "Environment not support. Pleas see https://docs.qmk.fm for details on how to configure the QMK Firmware build tools"
esac
