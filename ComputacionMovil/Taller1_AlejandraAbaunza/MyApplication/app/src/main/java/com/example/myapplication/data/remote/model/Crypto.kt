package com.example.myapplication.data.remote.model
import kotlinx.serialization.Serializable

@Serializable
data class Crypto(
    val coin: String,
    val wallet: String,
    val network: String
)