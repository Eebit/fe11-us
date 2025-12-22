#!/usr/bin/env python3

import sys
import re

def analysis_symbol(fpath):
	results = []

	dump_results = False
	# dump_results = True

	with open(fpath, 'r') as f:
		for line in f:
			line = line.strip()
			if not line:
				continue

			match = re.match(r'(\w+)\s+kind:([\w\(\)\=,]+)\s+addr:(\w+)', line)
			if match:
				name, kind, addr = match.groups()
				results.append({
					'name': name,
					'kind': kind.split('(')[0],
					'addr': addr
				})

	if dump_results:
			for item in results:
				print(f"name: {item['name']}")
				print(f"Kind: {item['kind']}")
				print(f"addr: {item['addr']}")
				print("-" * 40)

	return results

def find_line(fpath, str):
	with open(fpath, 'r') as f:
		for line in f:
			line = line.strip()
			if not line:
				continue

			if str in line:
				return line

	return None

def generate_unk_funcs(syms):
	fpath_unk_func = "include/unknown_funcs.h"

	for sym in syms:
		name = sym['name']
		kind = sym['kind']

		if kind == 'function':
			exists = find_line(fpath_unk_func, name)

			if exists:
				print(f"{exists}")
			else:
				print(f"// EC ??? {name}")

def analysis_unk_funcs():
	print("// ==============================")
	print("// arm9")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/symbols.txt"))
	print("")

	print("// ==============================")
	print("// itcm")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/itcm/symbols.txt"))
	print("")

	print("// ==============================")
	print("// dtcm")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/dtcm/symbols.txt"))
	print("")

	print("// ==============================")
	print("// oerlay0")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov000/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay1")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov001/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay2")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov002/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay3")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov003/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay4")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov004/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay5")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov005/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay6")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov006/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay7")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov007/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay8")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov008/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay9")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov009/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay10")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov010/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay11")
	print("// ==============================")
	generate_unk_funcs(analysis_symbol("config/YFEE01/arm9/overlays/ov011/symbols.txt"))
	print("")

def generate_unk_data(syms):
	fpath_unk_data = "include/unknown_data.h"

	for sym in syms:
		name = sym['name']
		kind = sym['kind']

		if kind == 'bss' or kind == 'data':
			exists = find_line(fpath_unk_data, name)

			if exists:
				print(f"{exists}")
			else:
				print(f"// extern ??? {name}")

def analysis_unk_data():
	print("// ==============================")
	print("// arm9")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/symbols.txt"))
	print("")

	print("// ==============================")
	print("// itcm")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/itcm/symbols.txt"))
	print("")

	print("// ==============================")
	print("// dtcm")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/dtcm/symbols.txt"))
	print("")

	print("// ==============================")
	print("// oerlay0")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov000/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay1")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov001/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay2")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov002/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay3")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov003/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay4")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov004/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay5")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov005/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay6")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov006/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay7")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov007/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay8")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov008/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay9")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov009/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay10")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov010/symbols.txt"))
	print("")
 
	print("// ==============================")
	print("// oerlay11")
	print("// ==============================")
	generate_unk_data(analysis_symbol("config/YFEE01/arm9/overlays/ov011/symbols.txt"))
	print("")

def main(args):
	# generate_unk_data()
	analysis_unk_data()


if __name__ == '__main__':
	main(sys.argv)
