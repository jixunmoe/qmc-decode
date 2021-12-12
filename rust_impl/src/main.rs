use std::{env, process};

mod qmc_crypto;
mod qmc_decode;

fn main() {
    let argv: Vec<String> = env::args().collect();
    let argc = argv.len();

    if argc < 3 {
        eprintln!("usage: {} <input> <output> [ignored]", argv[0]);
        process::exit(1);
    }

    eprintln!("QMC decoder (cli) v1.0 by Jixun\n");

    let input_file = argv[1].to_owned();
    let output_file = argv[2].to_owned();
    qmc_decode::decode_qmc_file(&input_file, &output_file).expect("failed to decode");
}
