use std::fs::File;
use std::io::prelude::*;
use std::io::Result;

use crate::qmc_crypto;

const BUFFER_SIZE: usize = 4096;

pub fn decode_qmc_file(input_path: &str, output_path: &str) -> Result<()> {
    let file_in = File::open(input_path);
    let mut file_in = match file_in {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let file_out = File::create(output_path);
    let mut file_out = match file_out {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut buffer = [0_u8; BUFFER_SIZE];
    let mut offset = 0_usize;

    loop {
        let read_result = file_in.read(&mut buffer);

        let read_size = match read_result {
            Ok(0) => return Ok(()),
            Ok(result) => result,
            Err(e) => return Err(e),
        };

        qmc_crypto::transform_qmc_buffer(&mut buffer[0..read_size], &mut offset);
        file_out
            .write(&buffer[0..read_size])
            .expect("could not write data to output file");
    }
}
