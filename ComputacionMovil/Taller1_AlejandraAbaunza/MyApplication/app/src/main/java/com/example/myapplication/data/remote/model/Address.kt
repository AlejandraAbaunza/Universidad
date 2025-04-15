package com.example.myapplication.data.remote.model

import kotlinx.serialization.Serializable

@Serializable
data class Address(
    val address: String,
    val city: String,
    val state: String,
    val statecode: String? = null,
    val postalcode: String? = null,
    val coordinates: Coordinates,
    val country: String,
)