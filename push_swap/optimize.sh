#!/bin/sh

# ARG=$(python3 rand_nums.py -20 20 20)
# push=$(./push_swap $ARG | wc -l)
# printf "%-40s avg:%s ARG: %s\n" "Random Simple instruction count (< 13)" "$push" "$ARG"

# ./push_swap "-5 19 1 9 4 -17 2 15 7 -19 -13 -12 20 -6 6 13 -7 -3 0 -18"

# ./push_swap "-19 75 49 -85 60 -37 -96 -94 -20 -75 -33 51 -15 -90 3 48 -88 26 -47 91 -13 94 37 47 -30 -73 -64 -60 -26 93 -79 -39 27 -66 96 74 -18 -12 -14 80 -56 -82 24 -59 46 63 -41 -70 -35 -24 13 -65 7 58 17 68 44 34 65 100 36 14 -34 -52 -87 95 -92 -97 12 97 -7 23 10 -11 -25 -53 -100 -98 71 22 -17 35 70 -9 -67 77 -21 40 66 -99 82 -28 28 -77 -8 18 -62 88 -95 50"
./push_swap "-122 11 -59 152 -401 439 -380 -403 -493 -475 236 -313 -376 -430 499 415 -107 470 109 456 -53 235 129 270 -387 -125 -267 -416 356 146 -388 317 246 -223 97 296 -182 -473 -379 178 380 -112 -12 28 -191 410 241 420 -481 -370 370 -202 95 481 -152 -85 -269 99 -23 -54 -352 -235 -443 300 464 153 -32 -185 26 -108 -210 -394 303 377 -131 159 44 -426 48 -261 -460 433 65 -456 165 -116 -198 328 -67 163 -472 -154 -252 340 -33 473 -206 167 -468 81 475 -64 -208 257 298 389 -134 472 -407 440 -129 40 -218 494 -270 -43 451 463 -92 -433 496 -172 226 -498 9 135 -248 -233 218 -278 -119 183 -265 -201 155 -193 147 -273 142 -424 483 -463 -56 -251 227 125 -212 -306 398 -93 -15 145 -386 169 399 254 393 -34 -40 175 -373 429 361 -79 344 427 476 -448 -415 -215 -336 -234 289 -228 180 -18 -263 -35 401 -293 384 484 168 -165 367 422 -231 -310 -322 0 -183 -38 -177 -299 -75 474 92 -36 253 442 198 431 -372 2 351 -114 -489 292 -61 -410 490 310 -26 14 -349 -156 -148 333 -260 29 170 -30 397 465 -130 -476 467 54 -2 -174 41 1 69 428 201 76 -334 247 74 88 -45 -414 -289 320 294 47 116 308 -160 -315 -184 182 450 -5 18 -419 -325 -250 -63 -214 337 209 -163 461 -37 250 27 -427 -241 446 45 285 72 62 -76 319 -378 -91 196 462 373 444 345 411 -133 207 -39 39 -186 85 -77 343 96 339 -19 -229 -332 -48 98 -417 21 402 -49 -413 -466 31 25 189 -94 -471 -274 441 205 -408 -51 32 80 -423 118 372 -361 452 127 -44 203 -257 242 83 -453 -451 437 46 -479 -176 -461 6 -357 -342 -314 471 -490 366 -364 -70 10 -65 498 -179 -209 -194 291 349 447 -343 392 -391 249 16 91 368 -330 -266 -301 101 432 -10 -58 -66 55 -404 -309 -240 100 220 -50 406 -298 -57 181 -393 -99 7 385 -239 -449 -385 -487 421 453 260 30 -302 -238 -31 -101 -121 194 357 -469 301 154 13 -124 35 -128 111 -95 -484 -141 327 188 50 59 -47 -120 -196 -369 214 -292 150 305 -333 275 -311 -398 448 -11 -98 199 229 265 122 315 487 -435 348 228 396 114 -389 495 71 -351 -324 374 -286 -217 -197 489 -253 276 139 202 259 -271 445 -303 -304 -318 -109 222 271 -459 -224 -362 350 204 -104 77 22 269 -268 -279 137 282 -399 197 255 -432 216 -181 -290 -138 -355 245 365 -392 394 369 -455 115 309 252 -80 281 347 -327 -167 413 486"
# can use > test.txt to see all outputs
#93 steps